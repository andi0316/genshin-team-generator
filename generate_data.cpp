#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int num_characters = 41;
string output_file = "abyss_clear_times.csv";

//generating our 4-person teams from the 41 characters available
//combinations (given n, choose k)
vector<array<int, 4>> generateTeamCombinations() {
    vector<array<int, 4>> teams;    //our teams vector :fire: emoji

    for (int i = 1; i <= num_characters - 3; ++i) {     //holy this is probably mad inefficient sorry chat
        for (int j = i + 1; j <= num_characters - 2; ++j) {
            for (int k = j + 1; k <= num_characters - 1; ++k) {
                for (int l = k + 1; l <= num_characters; ++l) {
                    teams.push_back({i, j, k, l});
                }
            }
        }
    }
    return teams;
}

//clear time algorithm w rand for times between 0 and max 600 secs ooo yeah
int getClearTime(const array<int, 4> team) {
    int clear_time = rand() % 601;
    return clear_time;
}

//writing to csv
void writeCSV(const vector<array<int, 4>> teams, string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {       //edge case
        cerr << "Failed to open file.\n";
        return;
    }

    for (auto team : teams) {   //populating the file + adding the clear time as writing
        int clearTime = getClearTime(team);
        outFile << team[0] << "," << team[1] << "," << team[2] << "," << team[3] << "," << clearTime << "\n";
    }

    outFile.close();
    cout << filename << " written successfully.\n";  //debugging
}

int main() {
    cout << "Generating teams..\n";
    //gets the team combos
    vector<array<int, 4>> allTeams = generateTeamCombinations();

    cout << "number of team combos made: " << allTeams.size() << "\n";  //debugging
    writeCSV(allTeams, output_file);

    return 0;
}
