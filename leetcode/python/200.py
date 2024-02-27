from collections import deque

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    res += 1
                    queue = deque()
                    queue.append((i, j))
                    while len(queue) > 0:
                        x, y = queue.popleft()
                        if grid[x][y] == '0':
                            continue
                        else:
                            if x + 1 < len(grid) and grid[x + 1][y] == '1':
                                queue.append((x + 1, y))
                            if y + 1 < len(grid[0]) and grid[x][y + 1] == '1':
                                queue.append((x, y + 1))
                            
                            if x - 1 >= 0 and grid[x - 1][y] == '1':
                                queue.append((x - 1, y))
                            if y - 1 >= 0 and grid[x][y - 1] == '1':
                                queue.append((x, y - 1))
                            grid[x][y] = '0'
        
        return res
        