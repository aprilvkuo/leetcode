#include "Sort.h"

Sort::Sort()
{
    //ctor
}

void Sort::heapify(vector<int> &data) {
    for (int i = data.size() / 2; i >= 0; i--) {
        heapify(data, i, data.size());
    }
}
/*向下调整堆*/
void Sort::heapify(vector<int> &data, int index, int max_size) {
    int left = (index + 1) * 2 - 1;
    int right = (index + 1) * 2;
    int origin_index = index;
    if (left  < max_size && data[origin_index] > data[left]) {
        origin_index = left;
    }
    if (right  < max_size && data[origin_index] > data[right]) {
        origin_index = right;
    }
    if (origin_index != index) {
        swap(data[origin_index], data[index]);
        heapify(data, origin_index, max_size);
    }
}

void Sort::heappush(vector<int> &data, int item) {
    data.push_back(item);
    int current_index = data.size();
    while (current_index > 1) {
        int father_index = current_index / 2;
        if (data[father_index - 1] > data[current_index - 1]) {
            swap(data[father_index - 1], data[current_index - 1]);
        } else {
            break;
        }
        current_index = father_index;
    }
    return;
}

int Sort::heappop(vector<int> &data) {

    swap(data[0], data[data.size()-1]);
    int return_data = data.back();
    data.pop_back();
    heapify(data, 0, data.size());
    return return_data;
}

/* 默认使用最小堆 */
void Sort::heap_sort(vector<int> &data) {
    heapify(data);
    cout << "build heap done" << endl;
    int heap_size = data.size();
    while (heap_size != 0) {
        swap(data[0], data[heap_size - 1]);
        heap_size --;
        heapify(data, 0, heap_size);
    }
}

void Sort::partition(std::vector<int>& nums, int left, int right){
    if (left >= right) {
        return;
    }
    int pivot = nums[left], l = left, r = right;
    while(l < r){
        while (l < r && nums[r] >= pivot)
            --r;
        std::swap(nums[l], nums[r]);
        while (l < r && nums[l] < pivot)
            ++l;
        std::swap(nums[l], nums[r]);
    }
    partition(nums, left, r-1);
    partition(nums, r+1, right);
    return;
}

void Sort::quick_sort(std::vector<int>& nums, int left, int right) {
     if (left >= right){
         return;
     }
     int pivot = nums[right], have_seen = left - 1;
     for (int i = left; i < right; i++) {
         if (nums[i] < pivot) {
             have_seen ++;
             std::swap(nums[i], nums[have_seen]);
         }
     }
     have_seen++;
     std::swap(nums[right], nums[have_seen]);
     quick_sort(nums, left, have_seen-1);
     quick_sort(nums, have_seen+1, right);
     return;

 }

void Sort::quick_sort(std::vector<int>& nums, int mode) {
    if (mode == 0) {
        partition(nums, 0, nums.size()-1);
    }
    else {
        quick_sort(nums, 0, nums.size()-1);
    }
    return;
}

Sort::~Sort()
{
    //dtor
}
