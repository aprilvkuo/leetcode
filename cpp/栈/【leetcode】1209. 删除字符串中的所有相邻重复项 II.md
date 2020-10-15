#### [1209. 删除字符串中的所有相邻重复项 II](https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii/)



```shell
给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。

 

示例 1：

输入：s = "abcd", k = 2
输出："abcd"
解释：没有要删除的内容。
示例 2：

输入：s = "deeedbbcccbdaa", k = 3
输出："aa"
解释： 
先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
再删除 "bbb"，得到 "dddaa"
最后删除 "ddd"，得到 "aa"
示例 3：

输入：s = "pbbcggttciiippooaais", k = 2
输出："ps"

提示：

1 <= s.length <= 10^5
2 <= k <= 10^4
s 中只含有小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```

执行用时 :8 ms, 在所有 C++ 提交中击败了99.68%的用户

内存消耗 :10.4 MB, 在所有 C++ 提交中击败了49.45%的用户

# 解法： 栈解法

输入字符串为s， 字母数为k。 依次将字符串中的字符压入栈中。

1.  当栈顶的k个字符相同时，则说明存在连续k个相同的字符，则将这k个相同字符弹出（即删除）。（时间复杂度为O(kn）)。
2.  进阶： 为了减少时间复杂度，需要减少判断是否存在`连续k个相同的字符`的次数。 所以当栈顶存在m个相同字符（判断是否存在`连续k个相同的字符`）， m < k， 在经过k-m个字符后， 再次（判断是否存在`连续k个相同的字符`）。（时间复杂度为O(k/2 = k * n * 2/n) ）

说明： 

当栈顶存在m个相同字符， 在将k-m个字符压入栈中：

1. 如果这k-m个元素与m个元素完全相同，则满足k个完全相同元素。
2. 否则， 则从新开始计算，得到新的m。



eg: 

S = "aaabbac",    k = 3

第一次判断： 栈(a)   m=1,  k=3, 存在1个相同字符。  k-m = 2

第二次判断： 栈(a a a)   m=3,  k=3, 存在3个相同字符。  k-m = 0， 并将栈顶k个元素pop。

第三次判断： 栈(b)  m=1,  k=3, 存在1个相同字符。  k-m = 2

第三次判断： 栈(b b a)  m=1,  k=3, 存在1个相同字符。  k-m = 2

第三次判断： 栈(b b a c)  m=1,  k=3, 存在1个相同字符。  k-m = 2



```c++
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<char> res;
        int next_size = 0;
        for (int i = 0; i < s.size(); i++) {
            res.push_back(s[i]);
            if (next_size <= 0) {
                while (res.size() >= k) {
                bool rm_flag = true;
                for (int i = 1; i < k; i++) {
                    if (res[res.size()-i] != res[res.size()-i-1]) {
                        rm_flag = false;
                        next_size = k - i;
                        break;
                    }
                }
                if (rm_flag) {
                    for (int i = 0; i < k; i++) {
                        res.pop_back();
                    }
                } else {
                    break;
                }
            }
            }
            next_size--;  
           
        }
        string res_str = "";
        for (int i = 0; i < res.size(); i++) {
            res_str += res[i];
        }
        return res_str;
    }
};
```

