/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\4.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-09
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
#include <set>
using namespace std;



class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1= nums1.size();
		int len2= nums2.size();

		if (len1 > len2)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

        /*
         * ci 为第i数组的割
         * 比如c1为2时，表示割第1个数组，左边只有2个元素
         * left_maxi  为第i个数组割后的左边元素最大值
         * right_mini 为第i个数组割后的右边元素最小值
         * 一个长度为n、边界值为n-1的数组，虚拟加了'#'、数组的边界值为2*n + 1 -1、长度为2*n + 1
         */
		int left_max1, left_max2, right_min1, right_min2;
        int c1, c2, lo = 0, hi = 2 * len1;  

		while (lo <= hi)  
		{
			c1 = (lo + hi) / 2;   //c1是二分查找的结果
			c2 = len1 + len2 - c1;//我们只需找到(2*(len1+len2)+2)/2 、(2*(len1+len2)+2)/2+1，就可以得到中值

			left_max1  = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];//左边最大值
			right_min1 = (c1 == 2 * len1) ? INT_MAX : nums1[c1 / 2];//右边最小值
			left_max2  = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			right_min2 = (c2 == 2 * len2) ? INT_MAX : nums2[c2 / 2];

			if (left_max1 > right_min2)
				hi = c1 - 1;
			else if (left_max2 > right_min1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(left_max1, left_max2) + min(right_min1, right_min2)) / 2.0;
	}
};