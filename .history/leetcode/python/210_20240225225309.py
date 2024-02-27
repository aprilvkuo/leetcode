class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indregress = [0] * numCourses
        adjacency = [[] for _ in range(numCourses)] 
        queue = []
        learning_list = []

        for a, b in prerequisites:
            indregress[a] += 1
            adjacency[b].append(a)

        for i in range(numCourses):
            if indregress[i] == 0:
                queue.append(i)
        while len(queue) > 0:
            new_queue = []
            for a in queue:
                learning_list.append(a)
                for b in adjacency[a]:
                    indregress[b] -= 1
                    if indregress[b] == 0:
                        new_queue.append(b)
            queue = new_queue
        
        for i in range(numCourses):
            if indregress[i] > 0:
                return []
        return learning_list