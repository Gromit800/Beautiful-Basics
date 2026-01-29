//
// Created by Alexandre Plaisance on 2025-12-22.
// Proof of concept before implemmenting AWS Lambda and frontend.
//

#include <iostream>
#include <string>

#include "hat.hpp"
#include "json.hpp"
#include "logic.hpp"
using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv) {
    // Check for empty input
    if (argc < 2 || argv[1][0] == '\0') {
        cout << "No pattern provided." << endl;
        return 1;
    }

    string input = argv[1];

    json data = parse_json(input);
    int pattern = process_pattern_request(data);

    switch (pattern) {
        case 1: {
            // Case hat;
            Hat hat(data);
            cout << fill_template("hat.html", hat.hat_map) << endl;

            break;
        }
        case 2:
            // Case pullover;
            break;
        case 3:
            // Case cardigan;
            break;
        case 4:
            // Case mittens;
            break;
        case 5:
            // Case socks;
            break;
        default:
            cout << "Unknown pattern." << endl;
            return 1;
    }

    return 0;
}
