/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0) return res;
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int preL = intervals[0][0];
        int preR = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int curL = intervals[i][0];
            int curR = intervals[i][1];
            if (preR < curL) {
                res.push_back({preL, preR});
                preL = curL;
                preR = curR;
            } else if (preR < curR) {
                preR = curR;
            }
        }
        res.push_back({preL, preR});
        return res;
    }
};
// @lc code=end
