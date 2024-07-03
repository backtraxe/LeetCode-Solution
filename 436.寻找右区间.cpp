/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> leftValAndIdx(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            leftValAndIdx[i][0] = intervals[i][0];
            leftValAndIdx[i][1] = i;
        }
        sort(leftValAndIdx.begin(), leftValAndIdx.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) { res[i] = binarySearch(leftValAndIdx, intervals[i][1]); }
        return res;
    }

    int binarySearch(vector<vector<int>>& nums, int target) {
        // 查找第一个大于等于 target 的元素
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m][0] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l < nums.size() ? nums[l][1] : -1;
    }
};
// @lc code=end
