#include <iostream>
#include <map>
#include <fstream>
#include <vector>
using namespace std;

//merges 2 sorted vectors
vector<float> merge(vector<float> a, vector<float> b){
    vector<float> result;
    auto ptr1 = a.begin();
    auto ptr2 = b.begin();

    while (ptr1 != a.end() && ptr2 != b.end()){
        if (*ptr1 < *ptr2){
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
vector<float> mergesort(vector<float>& arr){
    if (arr.size()<2){
        if (arr.size()==2 && arr[0]>arr[1])
        {
            float i = arr[0];
            arr[0] = arr[1];
            arr[1] = i;
        }
        return arr;
    }
    int mid = arr.size()/2;
    vector<float> left;
    vector<float> right;
    for (int i = 0; i < mid; i++){
        left.push_back(arr[i]);
    }
    for (int i = mid; i<arr.size(); i++){
        right.push_back(arr[i]);
    }
    left = mergesort(left);
    right = mergesort(right);
    vector<float> result = merge(left, right);
    return result;
}

int main(){

    map<int, string> characters;
    ifstream file("characters.txt");
    if (!file.is_open())
    {
        cout << "File could not be opened" << endl;
        return 0;
    }
    string s;
    for (int i = 0; i<41; i++)
    {
        getline(file, s);
        //cout<<s<<endl;
        characters[i] = s;
    }
    file.close();

    return 0;
}