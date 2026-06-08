#include <iostream>
using namespace std;

int main() {
    char S[1001]; 
    cin.getline(S, 1001);

    char normalized[1001]; 
    int len = 0; 
    while (S[len] != '\0') len++;

    int i = 0;
   
    while (i < len && (S[i] == ' ' || S[i] == '\t')) i++;

    int idx = 0;
    bool space_found = false;
    for (; i < len; i++) {
        if (S[i] == ' ' || S[i] == '\t') {
            space_found = true;
        } else {
            if (space_found && idx > 0) {
                normalized[idx++] = ' ';
                space_found = false;
            }
            
            char ch = S[i];
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch - 'A' + 'a';
            }
            normalized[idx++] = ch;
        }
    }
    normalized[idx] = '\0'; 

  
    int word_count = 0;
    if (idx > 0) {
        word_count = 1;
        for (int j = 0; j < idx; j++) {
            if (normalized[j] == ' ') word_count++;
        }
    }

    cout << word_count << "\n";
    cout << normalized << "\n";

    return 0;
}

