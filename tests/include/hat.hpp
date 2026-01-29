#ifndef HAT_HPP
#define HAT_HPP

#include <map>
#include <string>

#include "json.hpp"
using json = nlohmann::json;

using namespace std;

class Hat {
 public:
  Hat();

  // Matches the user inputs to the values in hat.json
  Hat(const json& input);

  Hat(string si, string ga, string co, string w, string st, string sr,
      string rr, string rm, string kt);

  Hat(Hat&);

  bool operator==(const Hat& other) const;
  void display();

  map<string, string> hat_map;
};

#endif
