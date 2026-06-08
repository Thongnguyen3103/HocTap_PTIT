#include <iostream>
#include <string>
using namespace std;

bool isSpecialEven(const string &n){
    if((n[n.size()-1]-'0') % 2 != 0) return false;  
    for(size_t i = 0; i < n.size(); i++){          
        if((n[i]-'0') % 2 != 0) return false;
    }
    return true;
}

int main(){
    int T; 
    cin >> T;
    while(T--){
        string N; 
        cin >> N;
        if(isSpecialEven(N)) cout << "YES\n";
        else cout << "NO\n";
    }
}
