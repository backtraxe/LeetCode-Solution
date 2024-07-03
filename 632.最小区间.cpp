/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 *
 * https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (61.14%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 47.1K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
 *
 * 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * 输出：[20,24]
 * 解释：
 * 列表 1：[4, 10, 15, 24, 26]，24 在区间 [20,24] 中。
 * 列表 2：[0, 9, 12, 20]，20 在区间 [20,24] 中。
 * 列表 3：[5, 18, 22, 30]，22 在区间 [20,24] 中。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [[1,2,3],[1,2,3],[1,2,3]]
 * 输出：[1,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] 按非递减顺序排列
 *
 *
 *
 *
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class Solution {
private:
    struct Node {
        int val;
        int rowIdx;
        int colIdx;

        Node(int val, int rowIdx, int colIdx) : val(val), rowIdx(rowIdx), colIdx(colIdx) {}
    };

    struct Comparator {
        // 反过来
        bool operator()(const Node& a, const Node& b) const { return a.val > b.val; }
    };

public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) return res;
        priority_queue<Node, vector<Node>, Comparator> pq;
        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            pq.emplace(nums[i][0], i, 0);
            maxVal = max(maxVal, nums[i][0]);
        }
        res.push_back(pq.top().val);
        res.push_back(maxVal);
        while (pq.size() == n) {
            Node node = pq.top();
            pq.pop();
            if (node.colIdx + 1 < nums[node.rowIdx].size()) {
                ++node.colIdx;
                node.val = nums[node.rowIdx][node.colIdx];
                pq.push(node);
                maxVal = max(maxVal, node.val);
                if (maxVal - pq.top().val < res[1] - res[0]) {
                    res[0] = pq.top().val;
                    res[1] = maxVal;
                }
            }
        }
        return res;
    }
};
// @lc code=end
