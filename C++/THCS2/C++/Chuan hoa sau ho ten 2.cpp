#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string s) {
    for (size_t i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
    return s;
}
string toUpperCase(string s) {
    for (size_t i = 0; i < s.size(); i++) s[i] = toupper(s[i]);
    return s;
}
string chuanHoaQuocTe(string s) { 
    while (!s.empty() && s[0] == ' ') s.erase(s.begin());
    while (!s.empty() && s[s.size()-1] == ' ') s.erase(s.end()-1);
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    if (words.empty()) return "";
    string ho = toUpperCase(words[0]);
    string result = "";
    for (size_t i = 1; i < words.size(); i++) {
        string w = toLowerCase(words[i]);
        if (!w.empty()) w[0] = toupper(w[0]);
        result += w;
        if (i != words.size()-1) result += " ";
    }

    if (!result.empty()) result += ", " + ho;
    else result = ho;
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);
        cout << chuanHoaQuocTe(s) << "\n";
    }

    return 0;
}

