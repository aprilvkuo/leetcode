#include "code.h"

bool Solution::Find(int target, vector<vector<int> > array) {
    if (array.size() == 0) {
        return false;
    }
    int size_0 = array.size();
    int size_1 = array[0].size();
    int x = 0, y = size_1 - 1;
    while (true) {
        if (x >= size_0 || y < 0) {
            return false;
        }
        if (array[x][y] == target) {
            return true;
        } else if (array[x][y] > target) {
            y --;
        } else {
            x ++;
        }
    }
    return true;
}
