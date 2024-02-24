/*
 * @lc app=leetcode.cn id=1255 lang=golang
 * @lcpr version=21705
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
var maxResult = 0
func traversal(words []string, score []int, wordIndex int, charCntDict map[byte]int, result int) {
	if wordIndex >= len(words) {
		return 
	}
	wordCharCnt := map[byte]int{}
	for _, char := range words[wordIndex] {
		wordCharCnt[byte(char)] ++
	}
	// 不包含单词
	traversal(words, score, wordIndex+1, charCntDict, result)
	// 包含单词
	
    hasWord := true
	for key, value := range wordCharCnt {
		if charCntDict[key] >= value {
		} else {
			hasWord = false
            break 
		}
	}
    if hasWord {
        for key, value := range wordCharCnt {
            charCntDict[key] -= value
            result += value * score[key-'a']
	    }
        if result > maxResult {
            maxResult = result
        }
	    traversal(words, score, wordIndex+1, charCntDict, result)
        // 恢复
        for key, value := range wordCharCnt {	
            charCntDict[key] += value
            result -= value * score[key-'a']
	    }

    }
	return

}

func maxScoreWords(words []string, letters []byte, score []int) int {
	total_char_cnt := map[byte]int{}
	for _, letter := range letters {
		total_char_cnt[byte(letter)]++
	}
	var result int
    maxResult = 0
	traversal(words, score, 0, total_char_cnt, result)
	return maxResult
}
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// ["dog","cat","dad","good"]\n["a","a","c","d","d","d","g","o","o"]\n[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// ["xxxz","ax","bx","cx"]\n["z","a","b","c","x","x","x"]\n[4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]\n
// @lcpr case=end

// @lcpr case=start
// ["leetcode"]\n["l","e","t","c","o","d"]\n[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]\n
// @lcpr case=end

 */


