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



// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> freq;           //for frequency of characters
//         priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
//         for(char c: s)
//             freq[c]++;
//         for(auto it: freq)
//             maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
//         s="";   
//         while(!maxheap.empty()){
//             s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
//             maxheap.pop();
//         }
//         return s;
//     }
    
    
    
    
//     // string frequencySort(string s) {
//     //     int counts[256] = {0};
//     //     for (char ch : s)
//     //         ++counts[ch];
//     //     sort(s.begin(), s.end(), [&](char a, char b) { 
//     //         return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
//     //     });
//     //     return s;
//     // }
// };