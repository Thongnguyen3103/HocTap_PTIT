#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int letters = 0, digits = 0, others = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isalpha((unsigned char)s[i])) letters++;
        else if (isdigit((unsigned char)s[i])) digits++;
        else others++;
    }

    cout << letters << " " << digits << " " << others;
    return 0;
}

