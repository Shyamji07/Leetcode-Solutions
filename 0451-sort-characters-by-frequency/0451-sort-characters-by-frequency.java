class Solution {
    public String frequencySort(String s) {
	// Count the occurence on each character
	HashMap<Character, Integer> cnt = new HashMap<>();
	for (char c: s.toCharArray()) {
		cnt.put(c, cnt.getOrDefault(c, 0) + 1);
	}

	// Build heap
	PriorityQueue<Character> heap = new PriorityQueue<>((a, b) -> (cnt.get(b) - cnt.get(a)));
	heap.addAll(cnt.keySet());

	// Build string
	StringBuilder sb = new StringBuilder();
	while (!heap.isEmpty()) {
		char c = heap.poll();
		for (int i = 0; i < cnt.get(c); i++) {
			sb.append(c);
		}
	}
	return sb.toString();
}
}