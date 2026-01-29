#include "logic.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

json parse_json(const string& input) {
  // Will be changed to deal with JSON string instead of file since frontend
  // will send JSON directly
  ifstream file(input);
  if (!file.is_open()) {
    cerr << "Could not open input file" << input << endl;
    exit(1);
  }

  try {
    json data = json::parse(file);
    return data;
  } catch (const json::parse_error& e) {
    cerr << "JSON parsing error: " << e.what() << endl;
    exit(1);
  }
}

int process_pattern_request(const json& input) {
  if (!input.contains("pattern")) {
    throw invalid_argument("JSON input does not contain 'pattern' key.");
    exit(1);
  }
  if (input["pattern"].is_number()) {
    return input["pattern"];
  } else if (input["pattern"].is_string()) {
    return stoi(input["pattern"].get<string>());
  }
  // Invalid pattern type
  return -1;
}

pair<string, string> process_hat_request(const json& input) {
  if (input.contains("size") && input.contains("gauge")) {
    string size = input["size"];
    string gauge = input["gauge"];
    return make_pair(size, gauge);
  }
  throw invalid_argument("JSON input does not contain required keys for hat.");
}

string fill_template(const string& template_name,
                     const map<string, string>& replacements) {
  string file_path = "patterns/" + template_name;

  if (getenv("LAMBDA_TAKS_ROOT")) {
    file_path = "/var/task/patterns/" + template_name;
  }

  ifstream file_in(file_path);
  if (!file_in.is_open()) {
    cerr << "Error: template file not found at " << file_path << endl;
    return "<h1>Error: System Template Missing</h1>";
  }

  stringstream buffer;
  buffer << file_in.rdbuf();
  string html_content = buffer.str();
  file_in.close();

  for (const auto& pair : replacements) {
    replace_all(html_content, "{{" + pair.first + "}}", pair.second);
  }

  return html_content;
}

void replace_all(string& str, const string& from, const string& to) {
  if (from.empty()) return;
  size_t pos = 0;
  while ((pos = str.find(from, pos)) != string::npos) {
    str.replace(pos, from.length(), to);
    pos += to.length();
  }
}
