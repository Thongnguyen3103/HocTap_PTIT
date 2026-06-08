#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T ;
    cin >> T ;

    while (T--){
        int n;
        cin >> n;

        if (n < 1 || n > 100000){
            cout << "So phan tu cua mang khong hop le !";
            return 1;
        }
        vector<int> arr(n);
        for (int i = 0 ; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        for (int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}                      

