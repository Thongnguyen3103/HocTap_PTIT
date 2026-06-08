# include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;

    if ( n <= 2 || n >= 100) {
        cout << "Gia tri khong hop le" << endl;
        return 0;
    }
    int a[100];
    for (int i =0; i < n; i++){
        cin >> a[i];
    }
     for (int i =0; i < n; i++){
        bool trung = false;
        for ( int j =0 ; j < i; j++){
            if (a[i] == a[j]){
                trung = true;
                break;
            }
        }
         if (!trung) {
            cout << a[i] << " ";
        }
    }
 return 0;
 }                         