/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (50.11%)
 * Likes:    2352
 * Dislikes: 0
 * Total Accepted:    888.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
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

        // 左边界升序，右边界降序
        sort(intervals.begin(), intervals.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        int preL = intervals[0][0];
        int preR = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int curL = intervals[i][0];
            int curR = intervals[i][1];
            if (preR < curL) {
                // 不重叠
                res.push_back({preL, preR});
                preL = curL;
                preR = curR;
            } else if (preR < curR) {
                // 重叠选最长右边界
                preR = curR;
            }
        }
        res.push_back({preL, preR});
        return res;
    }
};
// @lc code=end
