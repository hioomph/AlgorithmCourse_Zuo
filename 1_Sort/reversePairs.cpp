/**
 * @brief   归并分治
 *          LeetCode 493.翻转对
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int help[50001];

    int merge(vector<int>& nums, int l, int m, int r) {
        int ans = 0;
        for (int i = l, j = m+1; i <= m; i++) {
            while (j <= r && (long long)nums[i] > (long long)nums[j] * 2) {
                j++;
            }
            ans += j - m - 1;
        }

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

        return ans;
    }

    int reverse(vector<int>& nums, int l, int r) {
        if (l == r) {
            return 0;
        }

        int m = l + (r - l) / 2;
        return reverse(nums, l, m) + reverse(nums, m+1, r) + merge(nums, l, m, r);
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0;
        } 

        return reverse(nums, 0, nums.size() - 1);
    }
};