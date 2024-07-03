/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (77.07%)
 * Likes:    1149
 * Dislikes: 0
 * Total Accepted:    243.1K
 * Total Submissions: 315.4K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 *
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 *
 * 返回一个表示每个字符串片段的长度的列表。
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。
 *
 * 示例 2：
 *
 *
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string& s) {
        vector<vector<int>> indices(26, vector<int>(2, -1));
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (indices[idx][0] == -1) indices[idx][0] = i;
            indices[idx][1] = i;
        }
        sort(indices.begin(), indices.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> res;
        int i = 0;
        while (i < indices.size() && indices[i][0] == -1) ++i;
        if (i == indices.size()) return res;
        int preL = indices[i][0];
        int preR = indices[i][1];
        ++i;
        while (i < indices.size()) {
            if (preR <= indices[i][0]) {
                res.push_back(preR - preL + 1);
                preL = indices[i][0];
                preR = indices[i][1];
            } else {
                preR = max(preR, indices[i][1]);
            }
            ++i;
        }
        res.push_back(preR - preL + 1);
        return res;
    }
};
// @lc code=end
