/**
 * @brief 选择排序
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectSort(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return;
    }

    for (int minIdx, i = 0; i < nums.size() - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[minIdx] > nums[j]) {
                minIdx = j;
            }
        }
        swap(nums[i], nums[minIdx]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    selectSort(nums);

    for (int i = 0; i < n - 1; i++) {
        cout << nums[i] << " ";
    }
    cout << nums[n-1] << endl;
    
    return 0;
}