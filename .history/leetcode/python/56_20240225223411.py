class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        res = []
        for item in intervals:
            if len(res) == 0:
                res.append(item)
            else:
                if item[0] <= res[-1][1]:
                    res[-1][1] = max(res[-1][1], item[1])
                
                else:
                    res.append(item)
        return res


        