#### [1249. 移除无效的括号](https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses/)

```shell
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"
 

提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-remove-to-make-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```





## 解法： 栈

思路： 使用括号栈rm_stack， 记录“(”的下标。使用vector记录无效的括号下标rm_index。

1. 遇到“)”,  如果括号栈大小非空， 则栈pop。 即遇到了合理的括号对。
2. 遇到“)”,  如果括号栈大小为空， 则说明“）”无效，存储到rm_index中。
3. 遇到"(", 压入括号栈中。
4. 当遍历完数组，括号栈非空，说明是多出来的无效"(", 将下标存入rm_index.
5. 根据rm_index ， 重构有效的string

```python
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> rm_index;
        vector<int> rm_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                rm_stack.push_back(i);
            } else if (s[i] == ')') {
                if (rm_stack.empty()) {
                    rm_index.push_back(i);
                } else {
                    rm_stack.pop_back();
                }
            }
        }
        for (int i = 0; i < rm_stack.size(); i++) {
            rm_index.push_back(rm_stack[i]);
        }
        string res = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < rm_index.size() && i == rm_index[j]) {
                j++;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
```

