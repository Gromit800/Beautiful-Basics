#include "hat.hpp"

#include <iostream>
#include <string>

#include "logic.hpp"
using namespace std;

Hat::Hat() {
  hat_map["SIZE"] = "";
  hat_map["GAUGE"] = "";
  hat_map["CAST_ON"] = "";
  hat_map["WORK"] = "";
  hat_map["SWITCH_TO"] = "";
  hat_map["SETUP_ROUND"] = "";
  hat_map["REPEAT_ROUND"] = "";
  hat_map["REMAIN"] = "";
  hat_map["KTOG"] = "";
}

Hat::Hat(const json& input) {
  pair<string, string> hat_params = process_hat_request(input);
  string hat_file = "patterns/hat.json";
  json data = parse_json(hat_file);

  hat_map["SIZE"] = hat_params.first;
  hat_map["GAUGE"] = hat_params.second;

  // Should add a check here to ensure size and gauge exist in hat.json
  hat_map["CAST_ON"] =
      to_string(data["cast_on"][hat_params.first][hat_params.second]);
  hat_map["WORK"] =
      to_string(data["work"][hat_params.first][hat_params.second]);
  hat_map["SWITCH_TO"] =
      to_string(data["switch_to"][hat_params.first][hat_params.second]);
  hat_map["SETUP_ROUND"] =
      to_string(data["setup_round"][hat_params.first][hat_params.second]);
  hat_map["REPEAT_ROUND"] =
      to_string(data["repeat_round"][hat_params.first][hat_params.second]);
  hat_map["REMAIN"] =
      to_string(data["remain"][hat_params.first][hat_params.second]);
  hat_map["KTOG"] =
      to_string(data["ktog"][hat_params.first][hat_params.second]);
}

Hat::Hat(Hat& other) { hat_map = other.hat_map; }

Hat::Hat(string si, string ga, string co, string w, string st, string sr,
         string rr, string rm, string kt) {
  hat_map["SIZE"] = si;
  hat_map["GAUGE"] = ga;
  hat_map["CAST_ON"] = co;
  hat_map["WORK"] = w;
  hat_map["SWITCH_TO"] = st;
  hat_map["SETUP_ROUND"] = sr;
  hat_map["REPEAT_ROUND"] = rr;
  hat_map["REMAIN"] = rm;
  hat_map["KTOG"] = kt;
}

bool Hat::operator==(const Hat& other) const {
  if (hat_map == other.hat_map) return true;
  return false;
}

void Hat::display() {
  cout << "Hat Parameters:" << endl;
  cout << "Size: " << hat_map["SIZE"] << endl;
  cout << "Gauge: " << hat_map["GAUGE"] << endl;
  cout << "Cast on: " << hat_map["CAST_ON"] << endl;
  cout << "Work: " << hat_map["WORK"] << endl;
  cout << "Switch to: " << hat_map["SWITCH_TO"] << endl;
  cout << "Setup round: " << hat_map["SETUP_ROUND"] << endl;
  cout << "Repeat round: " << hat_map["REPEAT_ROUND"] << endl;
  cout << "Remain: " << hat_map["REMAIN"] << endl;
  cout << "K2tog: " << hat_map["KTOG"] << endl;
}
