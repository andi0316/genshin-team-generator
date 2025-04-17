#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<int, string> parse() {
    ifstream file("/Users/paulswenson/CLionProjects/genshin-team-generator/characters.txt");
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