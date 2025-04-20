#include <iostream>
#include "helpers.h"
#include "algorithms.h"
#include <map>
#include <algorithm>
using namespace std;

int main() {
    map<int, string> characterMap = parse();    //maps nums to genshins chars
    map<vector<int>, int> teamCombos = mappingTeams();  //maps teams to clear times

    // puts data from map to vector of pairs for easier sorting
    vector<pair<vector<int>, int>> teamData(teamCombos.begin(), teamCombos.end());
//    int count = 0;
//    // Debug print to make sure it's working
//    for (const auto& entry : teamData) {
//        for (int id : entry.first) {
//            cout << id << ",";
//        }
//        cout << ": " << entry.second << " seconds" << endl;
//        if (++count == 10) break; // testing to print 5 entries bc 100k is a lot lol
//    }

    vector<pair<vector<int>, int>> sortedTeams; //container for our sorted teams!

    sortedTeams = mergesort(teamData);
//    cout << "Top 5 fastest teams:\n";
//    int count = 0;
//    for (auto entry : sortedTeams) {
//        if (++count >= 189) {
//            cout << "Team" << count << ": ";
//            for (int id: entry.first) {
//                cout << id << " "; // optional: convert ID to name using the map
//            }
//            cout << "| Clear Time: " << entry.second << "s" << endl;
//        }
//        if (count >= 195) break;
//    }

    set<int> sample = {1,2,3,20,6,4};  //simulates a sample input

    vector<pair<vector<int>, int>> usableTeams = filter(sample, teamCombos);
    sortedTeams = mergesort(usableTeams);
//
//    for (int i = 0; i < min(10, (int)sortedTeams.size()); ++i) {
//        auto [team, time] = sortedTeams[i]; //easy access of key/team & value/time
//        cout << "team: ";
//        for (int member : team){
//            cout << member << " ";
//        }
//        cout << "--> clear time: " << time << "s" << endl;
//    }

    return 0;

}