# include <iostream>
# include <iomanip>
using namespace std;

int tong(int a, int b){
    return a + b;
    }
int hieu(int a, int b){
    return a - b;
    }
int tich(int a, int b){
    return a * b;
    }
float thuong(int a, int b){
    return (float)a / b;
    }
int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a , b;
    cin >> a >> b ;

    if (a < -999999 || a > 999999 || b < -999999 || b > 999999 ){
        cout << "Gia tri nhap khong hop le !";
        return 1;
    }
    
    cout << a << " + " << b << " = " << tong(a,b) << endl;
    cout << a << " - " << b << " = " << hieu(a,b) << endl;
    cout << a << " * " << b << " = " << tich(a,b) << endl;

    if (b == 0){
        cout << a << " / " << b << " = Phep tinh khong ton tai ";
        } else {
            cout << a << " / " << b << " = " << fixed << setprecision(5) << thuong(a,b);
            }
    return 0;
}             