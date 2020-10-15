题目描述

```shell
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

即： 输入为一个列表， 输出一个列表。输入列表为a， 输出的列表b， 每一个值b[i] = min(j-i) where a[j] > a[i]。 即输出的列表为，原列表中`下一个超过当前值` 的数与`当前值`的`最小下标差`
```





## 解法一： 简单dp

空间复杂度O(n), 时间复杂度O(n^2).

暴力方法的简单优化， 暴力方法，则从左到右，找到第一个超过当前值的下标。

优化：  如果`当前值`大于`前一个值`, 则使用`前一个值`的结果下标继续遍历。

```cpp
vector<int> dailyTemperatures_1(vector<int>& T) {
    vector<int> res;
    for (int i = 0; i < T.size(); i++) {
        int cnt = 0;
        if (i > 0 && T[i] >= T[i-1]){
            cnt = res.back()-1;
        }
        for (int j = cnt; j < T.size(); j++) {
            cnt++;
            if (T[i+j] > T[i]) {
                res.push_back(cnt);
                cnt = 0;
                break;
            }
        }
        if (cnt != 0 or i == T.size()-1) {
            res.push_back(0);
        }
    }
    return res;
}
```



## 解法二： 逆序， 栈解法

从右到左， 使用栈存储遍历过的值，栈顶里面放的是比`当前值大`的最近的数。

遵循规律：

1. 如果当前值大于栈顶值， 栈顶值推出（ 当前值比栈顶值大， 栈顶值无效）
2. 如果栈为空， 则将0压入， 无有效值。
3. 将当前值压入栈。

```cpp
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res;
    vector<int> stack;
    for (int i = T.size()-1; i >= 0; i--) {

        while (!stack.empty() && T[i] >= stack.back()) {
            stack.pop_back();
        }

        if (stack.empty())
            res.push_back(0);
        else
            res.push_back(stack.back()-i);

        stack.push_back(i);
    }
    return res;
}
```

