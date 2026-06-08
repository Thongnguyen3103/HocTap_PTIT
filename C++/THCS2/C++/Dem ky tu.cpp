#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    getline(cin, S);   

    int letters = 0, digits = 0, others = 0;

    for (size_t i = 0; i < S.size(); i++) {
    char c = S[i];
    if (isalpha(c)) 
        letters++;
    else if (isdigit(c)) 
        digits++;
    else 
        others++;
}

    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Others: " << others << endl;

    return 0;
}

