#include <bits/stdc++.h>
using namespace std;

string chuanHoa(string s) {
    while (!s.empty() && s[0] == ' ') s.erase(s.begin());
    while (!s.empty() && s[s.size() - 1] == ' ') s.erase(s.end() - 1);

    stringstream ss(s);
    string word, result = "";
    while (ss >> word) {
        for (size_t i = 0; i < word.size(); i++) {
            word[i] = tolower(word[i]);
        }
        if (!word.empty()) word[0] = toupper(word[0]);
        result += word + " ";
    }
    if (!result.empty()) result.erase(result.size() - 1); 
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string s;
        getline(cin, s);
        cout << chuanHoa(s) << "\n";
    }
    return 0;
}

