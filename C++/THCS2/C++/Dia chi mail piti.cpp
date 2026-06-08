#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;


string toLowerCase(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    string line;
    getline(cin, line); 
    line = toLowerCase(line);

    stringstream ss(line);
    string word;
    string lastName;  
    string result = "";

   
    while (ss >> word) {
        lastName = word;
    }

    ss.clear();
    ss.str(line);

   
    while (ss >> word) {
        if (word == lastName) break;
        result += word[0];
    }

   
    result += lastName;

    
    cout << result << "@ptit.edu.vn";

    return 0;
}

