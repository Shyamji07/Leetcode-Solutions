class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        n = len(obstacles)
        res = n*[1]
        v = []
        for i in range(n):
            tr = bisect_right(v, obstacles[i])
            if tr == len(v):
                v.append(obstacles[i])
            else:
                v[tr] = obstacles[i]
            res[i] = tr + 1
        return res