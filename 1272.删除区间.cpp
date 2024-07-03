/*
 * @lc app=leetcode.cn id=1272 lang=cpp
 *
 * [1272] 删除区间
 *
 * https://leetcode.cn/problems/remove-interval/description/
 *
 * algorithms
 * Medium (59.04%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '[[0,2],[3,4],[5,7]]\n[1,6]'
 *
 * 实数集合可以表示为若干不相交区间的并集，其中每个区间的形式为 [a, b)（左闭右开），表示满足 a <= x < b 的所有实数  x
 * 的集合。如果某个区间 [a, b) 中包含实数 x ，则称实数 x 在集合中。
 *
 * 给你一个 有序的 不相交区间列表 intervals 。intervals 表示一个实数集合，其中每一项 intervals[i] = [ai, bi]
 * 都表示一个区间 [ai, bi) 。再给你一个要删除的区间 toBeRemoved 。
 *
 * 返回 一组实数，该实数表示intervals 中 删除 了 toBeRemoved 的部分 。换句话说，返回实数集合，并满足集合中的每个实数 x
 * 都在 intervals 中，但不在 toBeRemoved 中。你的答案应该是一个如上所述的 有序的 不相连的间隔列表 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
 * 输出：[[0,1],[6,7]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：intervals = [[0,5]], toBeRemoved = [2,3]
 * 输出：[[0,2],[3,5]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
 * 输出：[[-5,-4],[-3,-2],[4,5],[8,9]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * -10^9 <= ai < bi <= 10^9
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        int n = intervals.size();

        if (n == 0) return res;

        // 删除区间之前
        int i = 0;
        while (i < n && intervals[i][1] <= toBeRemoved[0]) {
            res.push_back(intervals[i]);
            ++i;
        }

        // 删除区间开始
        if (i < n && intervals[i][0] < toBeRemoved[0]) { res.push_back({intervals[i][0], toBeRemoved[0]}); }

        // 删除区间结束
        while (i < n && intervals[i][1] <= toBeRemoved[1]) { ++i; }
        if (i < n && intervals[i][0] < toBeRemoved[1]) {
            res.push_back({toBeRemoved[1], intervals[i][1]});
            ++i;
        }

        // 删除区间之后
        while (i < n) {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};
// @lc code=end
