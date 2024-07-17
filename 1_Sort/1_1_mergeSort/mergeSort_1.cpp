/**
 * @brief ACM模式
 */

#include <iostream>
#include <vector>
using namespace std;

const int maxN = 100001;

vector<int> arr(maxN);
vector<int> help(maxN);
int n;

void merge(int l, int m, int r) {
    int i = l;
    int a = l;
    int b = m + 1;
    
    while (a <= m && b <= r) {
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    }

    while (a <= m) {
        help[i++] = arr[a++];
    }

    while (b <= r) {
        help[i++] = arr[b++];
    }

    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
}

// 归并排序递归版
void mergeSort1(int l, int r) {
    if (l == r) return;

    int m = (l + r) / 2;
    mergeSort1(l, m);
    mergeSort1(m+1, r);
    merge(l, m, r);
}

// 归并排序非递归版
void mergeSort2() {
    // 一共发生O(logn)次
    for (int l, m, r, step = 1; step < n; step <<= 1) {
        // 内部分组merge，时间复杂度O(n)
        l = 0;
        while (l < n) {
            m = l + step - 1;
            // 右为空，无需归并，直接保留左
            if ((m + 1) >= n) {
                break;
            }

            r = min(l + (step << 1) - 1, n - 1);
            merge(l, m, r);
            
            l = r + 1;  // 更新l
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 递归版
    mergeSort1(0, n-1);

    // 非递归版
    // mergeSort2();

    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << endl;

    return 0;
}
