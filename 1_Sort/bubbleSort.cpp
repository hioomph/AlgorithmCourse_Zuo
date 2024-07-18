/**
 * @brief 冒泡排序
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& nums) {
    if (nums.empty() || nums.size() < 2) {
        return;
    }

    for (int end = nums.size() - 1; end > 0; end--) {
        for (int i = 0; i < end; i++) {
            if (nums[i] > nums[i+1]) {
                swap(nums[i], nums[i+1]);
            }
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

    bubbleSort(nums);

    for (int i = 0; i < n - 1; i++) {
        cout << nums[i] << " ";
    }
    cout << nums[n-1] << endl;
    
    return 0;
}