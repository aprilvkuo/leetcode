#### [Leetcode] 331. 验证二叉树的前序序列化

#### https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/





## 栈解法

1. 直接去掉最后一个‘#’， 之后使用栈， 遇到数字进栈，遇到‘#’出栈，判断最后栈是否为空。（PS: #的个数是节点个数+1）



```cpp
class Solution {
public:

bool isValidSerialization(string preorder) {
    /*
     * https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
     */
    if (preorder == "#" or preorder == "")
        return true;

    if (preorder[preorder.size()-1] != '#') {
        return false;
    } else {
        preorder = preorder.substr(0, preorder.size() - 1);
    }

    vector<string> nodes;
    stringstream ss;
    string tmp;
    ss << preorder;
    while(getline(ss, tmp, ',')) {
        if (tmp == "#") {
            if (nodes.empty()) {
                return false;
            } else {
                nodes.pop_back();
            }
        } else {
            nodes.push_back(tmp);
        }
    }

    return nodes.empty()? true: false;
}
};
```



2. 解法二， 使用map， 每一个节点使用pair表示，度为2。 度数为0，则节点出栈。遇到‘#’或者有节点出栈，栈顶节点的度数减一。判断最后栈是否为空。



```cpp
bool isValidSerialization_1(string preorder) {
    /*
     * https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
     */
    if (preorder == "#")
        return true;
    vector<pair<string, int>> nodes;
    string num = "";
    int cnt = 0;
    for (int i = 0; i < preorder.size(); i++) {
        auto item = preorder[i];
        if (item == ',' or i == preorder.size()-1) {
            if (i == preorder.size()-1)
                num += item;
            if (num == "#") {
                if (nodes.empty())
                    return false;
                while (!nodes.empty()) {
                    auto &node = nodes.back();
                    if (node.second == 2) {
                        node.second--;
                        break;
                    } else {
                        nodes.pop_back();
                    }
                }
                num = "";
            }
            else {
                if (nodes.empty()){
                    cnt++;
                }
                if (cnt == 2){
                    return false;
                }
                nodes.push_back(make_pair(num, 2));
                num = "";
            }

        } else {
            num += item;
        }

    }
    return nodes.empty()? true: false;
}

```



## 度数解法

直接判断总度数是否为0， 每一个节点，度数减一； 非‘#’节点， 度数加2.

```cpp
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        string tmp;
        stringstream ss;
        ss << preorder;
        while(getline(ss, tmp, ',')){
            degree--;// consume one edge
            if(degree<0){
                return false;
            }
            if(tmp[0]!='#'){
                degree+=2;// generate 2 edges
            }
        }
        return degree == 0;
    }
};


```

