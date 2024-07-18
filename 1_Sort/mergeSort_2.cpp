/**
 * @brief LeetCode模式
 */

#include <iostream>
#include <vector>
using namespace std;

int help[50001];

void merge(vector<int>& nums, int l, int m, int r) {
    int i = l;
    int a = l;
    int b = m+1;

    while (a <= m && b <= r) {
        help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
    }

    while (a <= m) {
        help[i++] = nums[a++];
    }

    while (b <= r) {
        help[i++] = nums[b++];
    }

    for (int i = l; i <= r; i++) {
        nums[i] = help[i];
    }
}

// 递归版
void mergesort(vector<int>& nums, int l, int r){  
    if (l == r) {
        return;
    } else {  
        int m = (l + r) / 2;  
        mergesort(nums,l, m);  
        mergesort(nums, m + 1, r);  
        merge(nums, l, m, r);  
    }  
}  

vector<int> sortArray1(vector<int>& nums) {  
    if(nums.size() > 1)  
        mergesort(nums, 0, nums.size()-1);  
    return nums;  
}


// 非递归版   
void mergesort2(vector<int>& nums){  
    int n = nums.size();  
    for (int l, m, r, step = 1; step < n; step <<= 1) {  
        l = 0;  
        while (l < n) {  
            m = l + step - 1;  
            // 越界
            if (m + 1 >= n) {  
                break;  
            }  
            r = min(l + (step << 1) - 1, n - 1);  
            merge(nums, l, m, r);  
            l = r + 1;  
        }  
    }  
}

vector<int> sortArray2(vector<int>& nums) {  
    if(nums.size() > 1)  
        mergesort2(nums);  
    return nums;  
}  


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 递归版
    // sortArray1(arr);

    // 非递归版
    sortArray2(arr);

    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;

    return 0;
}