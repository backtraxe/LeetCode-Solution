/*
 * @lc app=leetcode.cn id=163 lang=cpp
 *
 * [163] 缺失的区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;
        int n = nums.size();

        if (n == 0) {
            res.push_back({lower, upper});
            return res;
        }

        if (nums.back() < lower || upper < nums.front()) {
            res.push_back({lower, upper});
            return res;
        }

        int preL = lower;
        for (int& x : nums) {
            if (x > upper) {
                break;
            } else if (x > preL) {
                res.push_back({preL, min(upper, x - 1)});
                preL = x + 1;
            } else if (x == preL) {
                ++preL;
            }
        }
        if (nums.empty() || nums.back() < upper) { res.push_back({preL, upper}); }
        return res;
    }
};
// @lc code=end
