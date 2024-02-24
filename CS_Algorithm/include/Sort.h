#ifndef SORT_H
#define SORT_H
#include <iostream>
#include "vector"
using namespace std;


class Sort
{
    public:
        Sort();

        // #################### quick sort ###################################
        static void quick_sort(std::vector<int>& nums, int mode=0); // 快排， mode表示不同的实现方式
        static void partition(std::vector<int>& nums, int left, int right);
        static void quick_sort(std::vector<int>& nums, int left, int right);

        // #################### heap sort ###################################
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
        virtual ~Sort();

    protected:

    private:
};

#endif // SORT_H
