#include <iostream>
#include "helpers.h"
#include <map>
using namespace std;

int main() {
    map<int, string> real = parse();
    for (const auto& pair : real) {
        cout << pair.first << ": " << pair.second << endl;
    }
}