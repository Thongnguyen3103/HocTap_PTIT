#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++)
        if(n % i == 0) return false;
    return true;
}

int sumDigits(int n){
    int s=0;
    while(n){ s += n%10; n/=10; }
    return s;
}

bool isFibo(int x){
    int f1=0,f2=1;
    while(f1<=x){
        if(f1==x) return true;
        int f=f1+f2;
        f1=f2; f2=f;
    }
    return false;
}

int main(){
    int a,b; cin >> a >> b;
    if(a>b) swap(a,b);
    for(int i=a;i<=b;i++){
        if(isPrime(i) && isFibo(sumDigits(i))){
            cout << i << " ";
        }
    }
}
