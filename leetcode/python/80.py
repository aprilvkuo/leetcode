from collections import defaultdict
class Solution(object):
    def removeDuplicates(self, nums):
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        print(nums)
        return i


a = Solution()
a.removeDuplicates([1,1,2,2,2,3])