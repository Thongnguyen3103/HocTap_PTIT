#include <iostream>
using namespace std;

int sumDigits(int n){
    int s = 0;
    while(n){ s += n % 10; n /= 10; }
    return s;
}

int main(){
    int a, b; 
    cin >> a >> b;
    int sa = sumDigits(a), sb = sumDigits(b);

    if(sa < sb) cout << a << " " << b;
    else if(sa > sb) cout << b << " " << a;
    else cout << a << " " << b; 
}
