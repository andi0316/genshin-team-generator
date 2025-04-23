    #include <iostream>
    #include "helpers.h"
    #include "algorithms.h"
    #include <map>
    #include <algorithm>
    #include <chrono>   //for measuring algo times
    using namespace std;
    using namespace std::chrono;    //for the chrono library, which is separate

    int main() {
        map<int, string> characterMap = parse();    //maps nums to genshins chars
        map<vector<int>, int> teamCombos = mappingTeams();  //maps teams to clear times

        // puts data from map to vector of pairs for easier sorting
        vector<pair<vector<int>, int>> teamData(teamCombos.begin(), teamCombos.end());

        vector<pair<vector<int>, int>> sortedTeams; //container for our sorted teams!
        vector<pair<vector<int>, int>> worstSortedTeams; //container for worst times lol

    //    sortedTeams = mergesort(teamData);
    //    set<int> sample = {1,2,3,20,6,4};  //simulates a sample input

        set<int> input = {}; //set of owned characters
        cout<<"Welcome to the Genshin Impact team generator"<<endl;
        cout<<"Please input all the characters you have (lowercase, first name only)."<<endl;
        cout<<"Type \"All\" for list of characters. Type \"End\" when finished."<<endl;
        string str;
        while (str!="End")
        {
            getline(cin, str);
            // cout<<"input: "<<str<<endl;
            auto i = characterMap.begin();
            while (str!="End"){
                if (i == characterMap.end() || str.empty())
                {
                    cout<<"Character not found."<<endl;
                    break;
                }
                if (i->second == str){
                    input.insert(i->first);
                    break;
                }
                if (str == "All"){
                    bool comma = false;
                    for(int i = 1; i < characterMap.size(); i++){
                        if(!comma) {
                            cout << characterMap[i];
                            comma = true;
                        }
                        else {
                            cout << ", " << characterMap[i];
                        }
                        if(i % 10 == 0){
                            cout << "\n";
                            comma = false;
                        }
                    }
                    break;
                }
                i++;
            }
        }

        if (input.size()<4)
        {
            cout<<"Please enter at least 4 characters"<<endl;
            return 0;
        }

        vector<pair<vector<int>, int>> usableTeams = filter(input, teamCombos);

        //edge case -- only 4 characters (one team possible)
        if(input.size() == 4){
            cout << "Only one team available: " << endl;
            for (auto [team, clear_time] : usableTeams){
                for (int member : team){    //filter thru the team's members
                    cout << characterMap[member] << " ";
                }
                cout << "\n" << "Clear time: " << clear_time << " seconds" << endl;
            }
            return 0;
        }

        //sorts the team using merge sort for min times + also tracks the time taken to do so
        auto mergeStart = high_resolution_clock::now();
        sortedTeams = mergesort(usableTeams);
        auto mergeEnd = high_resolution_clock::now();
        auto mergeSpeed = duration_cast<microseconds>(mergeEnd - mergeStart);

        //same as above for max heap
        auto heapStart = high_resolution_clock::now();
        worstSortedTeams = maxheapmake(usableTeams);
        auto heapEnd = high_resolution_clock::now();
        auto heapSpeed = duration_cast<microseconds>(heapEnd - heapStart);

        //print statements
        cout << "\nNumber of Usable Teams: " << usableTeams.size() << "\n";

        cout << "\nBest Times: " << endl;
        for (int i = 0; i < min(3, (int)sortedTeams.size()); ++i) {
            auto [team, time] = sortedTeams[i]; //easy access of key/team & value/time
            cout << "Team " << i+1 << ": ";
            for (int member : team){
                cout << characterMap[member] << ", ";
            }
            cout << "|| Clear Time: " << time << "s" << endl;
        }
        cout << "Merge Sort for Best Times Took: " << mergeSpeed.count() << " microseconds." << endl;

        cout << "\n" << "Worst Times: " << endl;
        for (int i = 0; i < min(3, (int)worstSortedTeams.size()); ++i) {
            auto [team, time] = worstSortedTeams[i]; //easy access of key/team & value/time
            cout << "Team " << i+1 << ": ";
            for (int member : team){
                cout << characterMap[member] << ", ";
            }
            cout << "|| Clear time: " << time << "s" << endl;
        }
        cout << "Heap Usage for Worst Times Took: " << heapSpeed.count() << " microseconds." << endl;


        return 0;

    }
