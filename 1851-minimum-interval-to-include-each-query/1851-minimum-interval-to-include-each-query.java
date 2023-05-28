import java.util.*;

class Solution {
    static class Comp implements Comparator<Pair<Integer, Integer>> {
        public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
            return p1.getKey().compareTo(p2.getKey());
        }
    }

    public int[] minInterval(int[][] intervals, int[] queries) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(new Comp());
        Map<Integer, Integer> result = new HashMap<>();
        List<Integer> sortedQueries = new ArrayList<>();
        for (int q : queries) {
            sortedQueries.add(q);
        }
        Collections.sort(sortedQueries);
        List<Pair<Integer, Integer>> sortedIntervals = new ArrayList<>();
        for (int[] interval : intervals) {
            sortedIntervals.add(new Pair<>(interval[0], interval[1]));
        }
        Collections.sort(sortedIntervals, new Comp());

        int i = 0;
        int n = intervals.length;
        for (int q : sortedQueries) {
            while (i < n && sortedIntervals.get(i).getKey() <= q) {
                int start = sortedIntervals.get(i).getKey();
                int end = sortedIntervals.get(i).getValue();
                pq.offer(new Pair<>(end - start + 1, end));
                i++;
            }
            while (!pq.isEmpty() && pq.peek().getValue() < q) {
                pq.poll();
            }
            result.put(q, pq.isEmpty() ? -1 : pq.peek().getKey());
        }

        int[] res = new int[queries.length];
        for (int j = 0; j < queries.length; j++) {
            res[j] = result.get(queries[j]);
        }
        return res;
    }
}
