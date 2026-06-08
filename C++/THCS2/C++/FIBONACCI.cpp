#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    unsigned long long f1 = 0, f2 = 1;
    for(int i=0;i<n;i++){
        if(i==0) cout << f1;
        else if(i==1) cout << " " << f2;
        else {
            unsigned long long f = f1 + f2;
            cout << " " << f;
            f1 = f2;
            f2 = f;
        }
    }
}
