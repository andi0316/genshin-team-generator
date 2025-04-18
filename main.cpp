#include <iostream>
#include "helpers.h"
#include <map>
using namespace std;

int main() {
    map<int, string> characterMap = parse();
//    for (const auto& pair : real) {
//        cout << pair.first << ": " << pair.second << endl;
//    }
    map<vector<int>, int> teamCombos = mappingTeams();
//    int count = 0;
//    for (const auto& entry : teamcombos) {
//        const vector<int>& team = entry.first;
//        int clearTime = entry.second;
//
//        // testing print
//        for (int member : team) {
//            cout << member << " ";
//        }
//        cout << ": " << clearTime << endl;
//
//        if (++count == 5) break; // testing to print 5 entries bc 100k is a lot lol
//    }

}