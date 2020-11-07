//
// Created by Guo,Hongjie on 2020-10-02.
//

#include "leetcode.h"

/*
 * 接雨水
 * https://leetcode-cn.com/problems/trapping-rain-water/
 * 1. 暴力法
 * 2. dp记录当前点， 左右的最高点
 * 3. 栈的应用， https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
 * 4. 双指针
 */


int trap(vector<int>& height, int type=0) {
    if (type == 0) {
        /*
         * 暴力法
         */
        int sum_num = 0;
        for (int i = 1; i < height.size(); i++) {
            int left_max = 0, right_max = 0;
            for (int j = i; j >= 0; j--) {
                left_max = max(left_max, height[j]);
            }
            for (int j = i; j < height.size(); j++) {
                right_max = max(right_max, height[j]);
            }
            sum_num += min(left_max, right_max) - height[i];
        }
        return sum_num;
    } else if (type == 1) {
        /*
         * dp
         */
        int sum_num = 0;
        if (height.size() == 0) return 0;
        vector<int> left_max(height.size(), 0), right_max(height.size(), 0);
        int max_left = 0;
        for (int i = 0; i < height.size()-1; i++) {
            max_left = max(max_left, height[i]);
            left_max[i+1] = max_left;
        }
        int max_right = 0;
        for (int i = height.size()-1; i > 0; i--) {
            max_right = max(max_right, height[i]);
            right_max[i-1] = max_right;
        }
        for (int i = 1; i < height.size(); i++) {
            sum_num += max(min(left_max[i], right_max[i]) - height[i], 0);
        }
        return sum_num;
    } else if (type == 2) {
        /*
         * stack
         */
        int sum_num = 0;
    }
    return 0;

}