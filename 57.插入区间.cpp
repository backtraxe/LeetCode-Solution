/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(std::move(intervals[i]));
            ++i;
        }
        int preL = newInterval[0];
        int preR = newInterval[1];
        while (i < n && preR >= intervals[i][0]) {
            preL = min(preL, intervals[i][0]);
            preR = max(preR, intervals[i][1]);
            ++i;
        }
        res.push_back({preL, preR});
        while (i < n) {
            res.push_back(std::move(intervals[i]));
            ++i;
        }
        return res;
    }
};
// @lc code=end
