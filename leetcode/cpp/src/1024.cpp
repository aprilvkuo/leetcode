//
// Created by April Kuo on 2020/10/24.
//

/*
 * https://leetcode-cn.com/problems/video-stitching/
 * 1024. 视频拼接
 * 1. 动态规划
 * 2. 贪心
 */
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> left_to_right(T+1, 0);
        for (auto &item: clips) {
            if (item[0] < T) {
                left_to_right[item[0]] = max(item[1], left_to_right[item[0]]);
            }
        }
        int pre = 0;
        int next = 0;
        int step = 0;
        for (int i = 0; i < T; i++) {
            next = max(left_to_right[i], next);
            if (i == next) {
                return -1;
            }
            if (pre == i) {
                pre = next;
                step ++;
            }
        }
        
        return step;
    }
};