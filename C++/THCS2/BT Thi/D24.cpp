# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>
using namespace std;

struct thisinh{
    int ma;
    string ten;
    string ngaysinh;
    double d1, d2, d3, dtong ;
};
bool cmp(const thisinh &a, const thisinh &b){
    if (a.dtong == b.dtong) return a.ma < b.ma ;
    return a.dtong < b.dtong ;
}
int main (){
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "So luong thi sinh khong hop le !";
        return 1;
    }
    
    vector<thisinh>ds(n);
    for ( int i = 0; i < n; i++){
        ds[i].ma = i + 1;
        cin.ignore();
        getline(cin, ds[i].ten);
        getline(cin, ds[i].ngaysinh);
        cin >> ds[i].d1 >> ds[i].d2 >> ds[i].d3 ;

        if (ds[i].d1 < 0 || ds[i].d1 > 10 ||
            ds[i].d2 < 0 || ds[i].d2 > 10 ||
            ds[i].d3 < 0 || ds[i].d3 > 10 ){
                cout << "Nhap diem khong hop le !";
                return 1;
        }
        ds[i].dtong = ds[i].d1 + ds[i].d2 + ds[i].d3 ;
    }
    
    stable_sort(ds.begin(),ds.end(),cmp);
    for (auto &ts : ds) {
        cout << ts.ma << " " << ts.ten << " " << ts.ngaysinh << " " << fixed << setprecision(2) << ts.dtong << endl;
    }
    return 0;
}        