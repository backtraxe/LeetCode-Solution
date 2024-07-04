/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.33%)
 * Likes:    2488
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size(), k);
    }

    int findKthLargest(vector<int>& nums, int begin, int end, int k) {
        // 分治思想，参考快排，降序，左侧元素更大，右侧元素更小
        // [begin, end)
        int l = begin;
        int r = end - 1;
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] <= pivot) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] >= pivot) ++l;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        // nums[l] 左侧元素数量为 l 个，即 nums[l] 是第 l + 1 个元素
        if (l + 1 == k) {
            // 当前元素即为第 k 大的元素
            return nums[l];
        } else if (l < k - 1) {
            // 左侧元素数量少于 k 个，在右侧继续查找第 k 个最大元素
            return findKthLargest(nums, l + 1, end, k);
        } else {
            // 左侧元素数量多于 k 个，在左侧继续查找第 k 个最大元素
            return findKthLargest(nums, begin, l, k);
        }
    }
};
// @lc code=end
