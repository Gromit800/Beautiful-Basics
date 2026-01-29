#include <iostream>

#include "hat.hpp"
#include "logic.hpp"
using namespace std;

int failures = 0;

void test_extraction() {
  // Test Case 1: Standard Number
  cout << "** Testing input pattern extraction... **\n";
  json j1 = {{"pattern", 10}, {"size", "s4"}, {"gauge", "16"}};
  if (process_pattern_request(j1) == 10) {
    cout << "[PASS] Number extraction\n";
  } else {
    cerr << "[FAIL] Number extraction\n";
    ++failures;
  }

  // Test Case 2: String Number
  json j2 = {{"pattern", "55"}, {"size", "s5"}, {"gauge", "18"}};
  if (process_pattern_request(j2) == 55) {
    cout << "[PASS] String extraction\n";
  } else {
    cerr << "[FAIL] String extraction\n";
    ++failures;
  }

  // Test Case 3: Missing Key (Should throw)
  json j3 = {{"size", "12m"}};
  try {
    process_pattern_request(j3);
    cerr << "[FAIL] Should have thrown error for missing key\n";
    ++failures;
  } catch (...) {
    cout << "[PASS] Missing key threw error\n";
  }
}

void test_hat() {
  // Test Case 1: Valid Size
  cout << "** Testing Hat creation... **\n";
  json j1 = {{"pattern", 1}, {"size", "s1"}, {"gauge", "12"}};
  Hat test("s1", "12", "32", "3.5", "5", "8", "3", "8", "4");
  Hat hat1(j1);

  if (hat1 == test) {
    cout << "[PASS] Hat creation matches expected values\n";
  } else {
    cerr << "[FAIL] Hat creation does not match expected values\n";
    cerr << "hat 1: ";
    hat1.display();
    cerr << endl;
    cerr << "test: ";
    test.display();
    cerr << endl;
    ++failures;
  }

  // Test Case 2: Invalid Size (Should throw)
  json j2 = {{"pattern", 1}, {"size", "xxl"}};
  try {
    Hat hat2(j2);
    cerr << "[FAIL] Should have thrown error for invalid size\n";
    ++failures;
  } catch (...) {
    cout << "[PASS] Invalid size threw error\n";
  }
}

int main() {
  cout << endl;
  cout << "---------- Running Test Suite ----------\n";
  test_extraction();
  test_hat();

  if (failures > 0) {
    cerr << "---------- Tests Failed: " << failures << " ----------\n";
    return 1;
  } else {
    cout << "---------- All Tests Passed! -----------\n";
    cout << endl;
  }
  return 0;
}
