class Solution:
	def pickGifts(self, gifts: List[int], k: int) -> int:
		while k > 0:
			max_pile = max(gifts)
			index = gifts.index(max_pile)
			gifts[index] = int(math.sqrt(max_pile))
			k = k - 1
		return sum(gifts)