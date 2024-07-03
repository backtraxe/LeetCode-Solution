/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int preL = intervals[0][0];
        int preR = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int curL = intervals[i][0];
            int curR = intervals[i][1];
            if (preR <= curL) {
                // 不相交
                preL = curL;
                preR = curR;
            } else {
                // 相交，需要移除右端点更大的区间
                if (preR > curR) {
                    preL = curL;
                    preR = curR;
                }
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
