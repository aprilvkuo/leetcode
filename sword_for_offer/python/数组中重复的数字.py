# -*- coding:utf-8 -*-

class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        # write code here
        for cnt,item in enumerate(numbers):
            if cnt != item:
                if numbers[cnt] == numbers[item]:
                    duplication[0] = item
                    print(item)
                    return True
                numbers[cnt],numbers[item] = numbers[item],item
        return False
a = Solution()
a.duplicate([2,1,3,1,4],[11])