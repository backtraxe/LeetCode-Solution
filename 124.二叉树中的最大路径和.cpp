/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (45.61%)
 * Likes:    2239
 * Dislikes: 0
 * Total Accepted:    422.8K
 * Total Submissions: 926.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 二叉树中的 路径
 * 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中
 * 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 *
 * 路径和 是路径中各节点值的总和。
 *
 * 给你一个二叉树的根节点 root ，返回其 最大路径和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3]
 * 输出：6
 * 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
 *
 * 示例 2：
 *
 *
 * 输入：root = [-10,9,20,null,null,15,7]
 * 输出：42
 * 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围是 [1, 3 * 10^4]
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
 * {}
 * };
 */

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
//         : val(x), left(left), right(right) {}
// };

#include <vector>
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) { return dfs(root)[1]; }

    vector<int> dfs(TreeNode* root) {
        // { 以root节点为端点的最大路径和，整体最大路径和 }
        if (!root) return {0, INT_MIN};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        // 以root节点为端点的最大路径和
        int cur_sum_1 = root->val;
        if (max(l[0], r[0]) > 0) cur_sum_1 += max(l[0], r[0]);
        // 包含root节点的最大路径和
        int cur_sum_2 = root->val;
        if (l[0] > 0) cur_sum_2 += l[0];
        if (r[0] > 0) cur_sum_2 += r[0];
        // 整体最大路径和
        int cur_sum_3 = max(cur_sum_2, max(l[1], r[1]));
        return {cur_sum_1, cur_sum_3};
    }
};
// @lc code=end
