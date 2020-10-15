class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        c,b = 0,len(nums)-1
        if len(nums) == 0:
            return False
        if nums[0]==target or nums[b] == target:
            return True
        while c < b-1:
            mid = (c+b)//2
            if nums[mid] == nums[c] == nums[b]:
                for i in range(c+1,b):
                    if nums[i] == target:
                        return True
                return False
            if target == nums[mid]:
                return True
            if target >= nums[c]:
                if nums[mid] >= nums[c]:
                    if nums[mid] >= target:
                        b = mid
                    else:
                        c = mid
                else:
                    b = mid
            else:
                if nums[mid] <= nums[b]:
                    if nums[mid] >= target:
                        b = mid
                    else:
                        c = mid
                else:
                    c = mid
        return False

a = Solution()
print(a.search([4,5,6,7,0,1,2],0))


