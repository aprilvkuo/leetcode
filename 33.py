class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        c,b = 0,len(nums)-1
        if len(nums) == 0:
            return -1
        if nums[0]==target:
            return 0
        if nums[b] == target:
            return b
        while c < b-1:
            mid = (c+b)//2
            print(c,b,mid)
            if target == nums[mid]:
                return mid
            if target>nums[c]:
                if nums[mid] > nums[c]:
                    if nums[mid] > target:
                        b = mid
                    else:
                        c = mid
                else:
                    b = mid
            else:
                if nums[mid] < nums[b]:
                    if nums[mid] > target:
                        b = mid
                    else:
                        c = mid
                else:
                    c = mid
        return -1

a = Solution()
print(a.search([4,5,6,7,0,1,2],0))