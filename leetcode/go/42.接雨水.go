/*
 * @lc app=leetcode.cn id=42 lang=golang
 * @lcpr version=21706
 *
 * [42] 接雨水
 */

// @lc code=start
func trap(height []int) int {
	leftIndex, rightIndex := 0, len(height)-1
	result := 0
	for {
		left, right := height[leftIndex], height[rightIndex]
		if left >= right {
			break
		}
		result += (rightIndex - leftIndex) * min(left, right)
		result += math.abs(left - right)
		for height[leftIndex] <= left && rightIndex > leftIndex {
			leftIndex++
		}
		for height[rightIndex] <= right && rightIndex > leftIndex {
			rightIndex--
		}
	}
	for _, item := range height {
		result -= item
	}
	return result

}

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

*/


