#ifndef DSA_PROJ_3_ALGORITHMS_H
#define DSA_PROJ_3_ALGORITHMS_H
#endif //DSA_PROJ_3_ALGORITHMS_H
#include <iostream>
#include <map>
#include <fstream>
#include <set>
using namespace std;

//filtering the teams to only use the ones inputted! takes in available chars + the teams
vector<pair<vector<int>, int>> filter(set<int>& available_chars, map<vector<int>, int>& all_teams){
    vector<pair<vector<int>,int>> usable_teams;

    for (auto [team, clear_time] : all_teams){
        bool valid = true;
        for (int member : team){    //iter thru the team's mems to make sure match
            if (available_chars.find(member) == available_chars.end()){
                valid = false;
                break;
            }
        }
        if (valid == true){
            usable_teams.emplace_back(team, clear_time);    //emplace inserts it in directly which is awesomer
        }
    }
    return usable_teams;
}


//sorting the vector pair bc sorting just cleartimes would make it hard to search for later on w/ dupes -andria
//merges 2 sorted vectors
vector<pair<vector<int>, int>> merge(vector<pair<vector<int>, int>>& a, vector<pair<vector<int>, int>>& b){
    vector<pair<vector<int>, int>> result;
    auto ptr1 = a.begin();
    auto ptr2 = b.begin();

    while (ptr1 != a.end() && ptr2 != b.end()){
        if (ptr1->second < ptr2->second){
            result.push_back(*ptr1);
            ptr1++;
        }
        else{
            result.push_back(*ptr2);
            ptr2++;
        }
    }
    while (ptr1 != a.end()){
        result.push_back(*ptr1);
        ptr1++;
    }
    while (ptr2 != b.end()){
        result.push_back(*ptr2);
        ptr2++;
    }
    return result;
}

//merge sorts vector of floats (ascending order)
vector<pair<vector<int>, int>> mergesort(vector<pair<vector<int>, int>>& arr){
    if (arr.size()<2){
        if (arr.size()==2 && arr[0].second >arr[1].second)
        {
            pair<vector<int>, int> temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr;
    }

    int mid = arr.size()/2;
    vector<pair<vector<int>, int>> left;
    vector<pair<vector<int>, int>> right;

    for (int i = 0; i < mid; i++){
        left.push_back(arr[i]);
    }
    for (int i = mid; i<arr.size(); i++){
        right.push_back(arr[i]);
    }
    left = mergesort(left);
    right = mergesort(right);
    vector<pair<vector<int>, int>> result = merge(left, right);
    return result;
}

//int main(){
//
//    map<int, string> characters;
//    ifstream file("characters.txt");
//    if (!file.is_open())
//    {
//        cout << "File could not be opened" << endl;
//        return 0;
//    }
//    string s;
//    for (int i = 0; i<41; i++)
//    {
//        getline(file, s);
//        //cout<<s<<endl;
//        characters[i] = s;
//    }
//    file.close();
//
//    return 0;
//}


