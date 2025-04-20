#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

map<int, string> parse() {
    ifstream file("characters.txt");
    string line;
    map<int, string> charmap;
    int i = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            charmap.emplace(i++, line);
        }
        file.close();
    } else {
        perror("Error opening file");
    }
    return charmap;
}

map <vector<int>, int> mappingTeams(){
    map<vector<int>, int> teamMap;

    ifstream file("abyss_clear_times.csv");
    string line;
    int i = 1;

    if (!file.is_open()) {
        cerr << "Error opening file";
        return teamMap;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string input;
        string time;
        vector<int> teams;

        //i < 4 to ensure repeat 4 times for each team member and also parses the value
        for (int i = 0; i < 4 && getline(ss, input, ','); i++) {
            teams.push_back(stoi(input));
        }
        getline(ss, time, ',');
        teamMap[teams] = stoi(time);

    }
    file.close();

    return teamMap;
}
vector<pair<vector<int>, int>> maxheapmake (vector<pair<vector<int>, int>>& a) {
    priority_queue <pair<vector<int>, int>> pq;
    for (int i=0; i <= a.size(); i++)
        pq.push(a[i]);
    vector<pair<vector<int>, int>> ret;
    while(pq.empty() == false) {
        ret.push_back(pq.top());
        pq.pop();
    }
    return ret;
}