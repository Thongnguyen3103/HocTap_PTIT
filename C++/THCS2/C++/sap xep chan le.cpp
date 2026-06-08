#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100];  
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> even_nums;
    vector<int> odd_nums;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_nums.push_back(arr[i]);
        } else {
            odd_nums.push_back(arr[i]);
        }
    }

    sort(even_nums.begin(), even_nums.end());
    sort(odd_nums.begin(), odd_nums.end());

    for (int i = 0; i < (int)even_nums.size(); i++) {
        cout << even_nums[i] << " ";
    }
    for (int i = 0; i < (int)odd_nums.size(); i++) {
        cout << odd_nums[i] << " ";
    }
    
    return 0;
}

