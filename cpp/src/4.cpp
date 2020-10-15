/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file    : 4.py
 * @author  : GuoHongjie 
 * @email   : guohongjie@baidu.com)
 * @date    : 2/9/2019, 5:51:30 PM
 *
 * 
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
 **/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0)
            if (nums2.size()%2)
                return nums2[nums2.size()/2];
            else
            {
                return (nums2[nums2.size()/2]+nums2[nums2.size()/2-1]) / 2.0;
            }
            
          if (nums2.size() == 0)
           if (nums1.size()%2)
                return nums1[nums1.size()/2];
            else
            {
                return (nums1[nums1.size()/2]+nums1[nums1.size()/2-1]) /2.0;
            }

        int total_num = nums1.size() + nums2.size();
        int left_num = total_num / 2;
        int index_num1, index_num2;
        int index_num1_min = 0;
        int index_num1_max = nums1.size()-1;
        int left_max, right_min;
        while (true){
            index_num1 = (index_num1_min+index_num1_max)/2;
            index_num2 = left_num - index_num1;
            if (index_num1 < index_num1_max && nums1[index_num1] < nums2[index_num2-1])
                index_num1_min = index_num1 + 1;
            else if (index_num1 > index_num1_min && nums1[index_num1-1] > nums2[index_num2])
                index_num1_max = index_num1 - 1;
            else
            {
                if (index_num1 == 0)
                    left_max = nums2[index_num2-1];
                else if (index_num2 == 0)
                    left_max = nums1[index_num1-1];
                else
                    left_max = max(nums1[index_num1-1], nums2[index_num2-1]);
                if (index_num1 == nums1.size())
                    right_min = nums2[index_num2];
                else if (index_num2 == nums2.size())
                    right_min = nums1[index_num1];
                else
                    right_min = min(nums1[index_num1], nums2[index_num2]);
                if (total_num % 2 == 1)
                    return right_min;
                else
                    return (left_max + right_min)/2.0;
            }
            
        }
    }
 
};