# Some Algorithms

# 0. UNIT TEST

Please see [main script](./main.cpp)

# 1. Pattern Match
## 1.1. Trie

[Trie Code](./include/Trie.h): ./include/Trie.h

```cpp
bool delete_word(const string &s); // 当单词不在字典中， 返回false
bool insert_word(const string &s); // 当单词已经在字典中， 返回false
bool search_word(const string &s, int mode=0);  // mode: 0 表示字典查询， 1 表示前缀查询
```

## 1.2. KMP
[KMP Code](./include/KMP.h): ./include/KMP.h

```cpp
static int kmp_match(const std::string &query, const std::string &word);
// ret code of -1 means: there is no match res
// ret code of k means : the begin position of query of first matched pattern

static std::vector<int> kmp_match_all(const std::string &query, const std::string &word);
// return : the begin position of query of all matched patterns
```

## 1.3. AC

## 1.4. RB TREE

# 2. Sort
[Sort Code](./include/Sort.h): ./include/Sort.h

## 2.1. Quick Sort

```cpp
static void quick_sort(std::vector<int>& nums, int mode=0); // 快排， mode 0、1表示不同的实现方式
```

## 2.2. Heap Sort
```cpp
/* 默认使用最小堆 */
/*建立堆*/
static void heapify(vector<int> &data);
/*向下调整堆*/
static void heapify(vector<int> &data, int index, int max_size);
/*往堆加入一个item， 并保持堆的特性*/
static void heappush(vector<int> &data, int item);
/* 从堆顶弹出一个元素， 并保持堆的特性， 最小堆*/
static int heappop(vector<int> &data);
/* 堆排序 */
void heap_sort(vector<int> &data);
```
# 3. Tree

## 3.1. Basic Operator 
[Tree Basic Code](./include/TreeBase.h): ./include/TreeBase.h

```cpp
   static TreeNode* build_tree(std::vector<std::string> data);
   // 通过vector进行建树， 按层建数， 不存在的节点为“NULL”
   static void pre_traverse(TreeNode *root, int mode=0);
   // 先序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
   static void mid_traverse(TreeNode *root, int mode=0);
   // 中序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
   static void suf_traverse(TreeNode *root, int mode=0);
   // 后序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
```

