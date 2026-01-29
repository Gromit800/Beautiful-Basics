#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <string>
#include <utility>

#include "json.hpp"
using json = nlohmann::json;
using namespace std;
// Parses the input string as JSON and returns the resulting json object.
json parse_json(const string& input);

// Validates the existence of a pattern key in the input JSON and processes it.
int process_pattern_request(const json& input);

// Processes hat-specific data from the input JSON and returns a size string.
pair<string, string> process_hat_request(const json& input);

// Fills the HTML template (the pattern) with the object's values
string fill_template(const string& template_name,
                     const map<string, string>& replacements);

void replace_all(string& str, const string& from, const string& to);

#endif
