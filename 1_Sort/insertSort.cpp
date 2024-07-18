/**
 * @brief 插入排序
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertSort(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return;
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int j = i - 1; j >= 0 && nums[j] > nums[j+1]; j--) {
            swap(nums[j], nums[j+1]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    insertSort(nums);

    for (int i = 0; i < n - 1; i++) {
        cout << nums[i] << " ";
    }
    cout << nums[n-1] << endl;
    
    return 0;
}