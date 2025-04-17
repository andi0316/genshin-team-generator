#include <iostream>
#include <map>
#include <fstream>
using namespace std;

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