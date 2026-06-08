#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    string name;
    string group;
    double buy;
    double sell;
    double profit;
};

bool cmp(const Item &a, const Item &b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        getline(cin, items[i].name);
        getline(cin, items[i].group);
        cin >> items[i].buy;
        cin >> items[i].sell;
        cin.ignore();
        items[i].profit = items[i].sell - items[i].buy;
    }

    sort(items.begin(), items.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << items[i].id << " " 
             << items[i].name << " " 
             << items[i].group << " " 
             << fixed << setprecision(2) << items[i].profit << "\n";
    }

    return 0;
}

