#### [921. 使括号有效的最少添加](https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/)



>  给定一个由 '(' 和 ')' 括号组成的字符串 S，我们需要添加最少的括号（ '(' 或是 ')'，可以在任何位置），以使得到的括号字符串有效。
>
> 从形式上讲，只有满足下面几点之一，括号字符串才是有效的：
>
> 它是一个空字符串，或者
> 它可以被写成 AB （A 与 B 连接）, 其中 A 和 B 都是有效字符串，或者
> 它可以被写作 (A)，其中 A 是有效字符串。
> 给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。

```
示例 1：

输入："())"
输出：1

示例 2：

输入："((("
输出：3
示例 3：

输入："()"
输出：0
示例 4：

输入："()))(("
输出：4

提示：

S.length <= 1000
S 只包含 '(' 和 ')' 字符。

```



## 解法： 栈解法

从左到右遍历，将括号压入栈中，并遵循以下的规律： `当栈顶元素是（， 且当前符号是），出栈`。最后栈的大小就是最终的括号数。时间O(n), 空间O(n).

```cpp
int minAddToMakeValid(string S) {
    vector<char> stack;
    for (auto item : S) {
        if (stack.empty()) {
            stack.push_back(item);
        } else if ( item == ')' and stack.back() == '('){
           stack.pop_back();
        } else {
            stack.push_back(item);
        }

    }
    return stack.size();
}
```

## 解法： 官方解法，平衡法

分别用`left`和`right`表示需要在左边添加的`(`和右边添加的`)`。

当从左到右遍历字符串时，显而易见的规律有（PS： 如果后边还出现`)`, 可以与right抵消，所以优先判断right的情况）：

1. 当遇到`(`, right需要加1.
2. 当遇到`)`,  如果right大于0， 可以抵消right（right--）。 如果right小于等于0， left ++。

```cpp
int minAddToMakeValid(string S) {
    int left = 0, right = 0;
    for (auto item : S) {
        if (item == '(') {
            right += 1;
        } else {
            right -= 1;
        }
        if (right == -1) {
            left ++;
            right ++;
        }

    }
    return left + right;
}
```

