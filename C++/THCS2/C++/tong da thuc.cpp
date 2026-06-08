#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

map<int,long long> parsePoly(const string &s) {
    map<int,long long> poly;
    stringstream ss(s);
    string term;
    while (ss >> term) {
        long long coef = 0;
        int exp = 0;
        size_t pos = term.find("x^");
        if (pos != string::npos) {
            coef = atol(term.substr(0,pos).c_str());
            exp  = atoi(term.substr(pos+2).c_str());
        } else {
            coef = atol(term.c_str());
            exp  = 0;
        }
        poly[exp] += coef;
        ss >> term; // b? qua d?u '+'
    }
    return poly;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string a,b;
        getline(cin,a);
        getline(cin,b);
        map<int,long long> A = parsePoly(a);
        map<int,long long> B = parsePoly(b);
        for (map<int,long long>::iterator it = B.begin(); it != B.end(); ++it)
            A[it->first] += it->second;

        bool first = true;
        for (map<int,long long>::reverse_iterator it = A.rbegin(); it != A.rend(); ++it) {
            if (it->second == 0) continue;
            if (!first) cout << " + ";
            cout << it->second << "x^" << it->first;
            first = false;
        }
        cout << endl;
    }
    return 0;
}

