# include <iostream>
# include <iomanip>
# include <set>
# include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if ( n < 2 || n > 100){
        cout << "Nhap gia tri n khong hop le!";
        return 1;
    }
    
    vector<int> A(n);
    for (int i = 0; i < n ; i++ ){
        cin >> A[i];
    }
    
    set<int> uniqueElemants ;
    vector<int> result;

    for (int x : A){
        if (uniqueElemants.find(x) == uniqueElemants.end()){
            uniqueElemants.insert(x);
            result.push_back(x);
        }
    }
    for (int x : result ){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}    
