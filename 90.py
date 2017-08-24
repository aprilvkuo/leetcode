# import itertools
# class Solution(object):
#     def subsetsWithDup(self, nums):
#         result = []
#         nums = sorted(nums)
#         for i in range(len(nums)+1):
#             for item in itertools.combinations(nums,i):
#                 result.append(",".join([str(ch) for ch in item]))
#         result = list(set(result))
#         result = [[int(item1) for item1 in item.split(',') if item1!=""] for item in result]
#         return result

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        res = [[]]
        S.sort()
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                l = len(res)
            for j in range(len(res) - l, len(res)):
                res.append(res[j] + [S[i]])
                print(res)
            print(i,res)
        return res

a = Solution()
print(a.subsetsWithDup([1,2,3,3]))

'''
[[], [1]]
0 [[], [1]]
[[], [1], [2]]
[[], [1], [2], [1, 2]]
1 [[], [1], [2], [1, 2]]
[[], [1], [2], [1, 2], [3]]
[[], [1], [2], [1, 2], [3], [1, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
2 [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3], [1, 3, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3], [1, 3, 3], [2, 3, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3], [1, 3, 3], [2, 3, 3], [1, 2, 3, 3]]
3 [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3], [1, 3, 3], [2, 3, 3], [1, 2, 3, 3]]
[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [3, 3], [1, 3, 3], [2, 3, 3], [1, 2, 3, 3]]
'''