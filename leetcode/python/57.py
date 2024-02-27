class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        is_add = False
        for item in intervals:
            if item[1] < newInterval[0]:
                res.append(item)
            elif item[0] > newInterval[1]:
                if is_add == False:
                    res.append(newInterval)
                    is_add = True
                res.append(item)
            else:
                newInterval[0] = min(newInterval[0], item[0])
                newInterval[1] = max(newInterval[1], item[1])
        if is_add == False:
            res.append(newInterval)
        return res
