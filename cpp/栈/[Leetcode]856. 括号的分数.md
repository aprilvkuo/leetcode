题目描述：

```shell
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
 

示例 1：

输入： "()"
输出： 1
示例 2：

输入： "(())"
输出： 2
示例 3：

输入： "()()"
输出： 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

## 栈解法

观察规律可以得到： 输入的字符串，可以分解成多个子模块。 F(x) = F1(x) + F2(x) + ...



当层在多层括号时，使用栈记录括号的层数n， base为2^(n-1),

1. 遇到第一个')', 则增加base。
2.  当出现连续‘）’，即非第一个‘）’，不处理。

```python
class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<char> s;
        int cnt = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                 s.push_back('(');
            } else if (S[i] == ')' && i - 1 >= 0 && S[i-1] == ')') {
                 s.pop_back();
                 continue;
            } else {                
                cnt += pow(2, s.size()-1);
                s.pop_back();
            }
        }
        return cnt;
    }
};
```

