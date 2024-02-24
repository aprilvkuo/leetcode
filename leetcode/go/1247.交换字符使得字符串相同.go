/*
 * @lc app=leetcode.cn id=1247 lang=golang
 * @lcpr version=21705
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
func minimumSwap(s1 string, s2 string) int {
    if len(s1) != len(s2) {
        return -1
    }
    countX, countY := 0, 0
    for index := 0; index < len(s1); index ++{
        if s1[index] == s2[index] {
            continue
        } else if string(s1[index]) == string("x") {
            countX++
        } else {
            countY++
        }
    }
    if (countX + countY) % 2  == 1{
        return -1
    }
 
    return countX / 2 + countY /2 + countX % 2 * 2
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// "xx"\n"yy"\n
// @lcpr case=end

// @lcpr case=start
// "xy"\n"yx"\n
// @lcpr case=end

// @lcpr case=start
// "xx"\n"xy"\n
// @lcpr case=end

// @lcpr case=start
// "xxyyxyxyxx"\n"xyyxyxxxyx"\n
// @lcpr case=end

 */


