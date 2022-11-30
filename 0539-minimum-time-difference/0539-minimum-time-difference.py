class Solution:
	def findMinDifference(self, arr: List[str]) -> int:
		list = []
		for s in arr:
			time = int(s[0:2])*60 + int(s[3:5])              
			list.append(time)   
			list.append(time + 60*24)

		list.sort()
		ans = 24*60
		for i in range(1,len(list)):
			ans = min(ans, list[i] - list[i-1])

		return ans