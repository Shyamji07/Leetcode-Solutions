/**
 * @param {number[][]} intervals
 * @param {number[]} queries
 * @return {number[]}
 */

    
var minInterval = function(intervals, queries) {
        class Comp {
            compare(p1, p2) {
                return p1[0] - p2[0];
            }
        }

        const pq = new priorityQueue(new Comp());
        const result = {};
        const sortedQueries = queries.slice().sort((a, b) => a - b);
        const sortedIntervals = intervals.slice().sort((a, b) => a[0] - b[0]);
        let i = 0;
        const n = intervals.length;

        for (const q of sortedQueries) {
            while (i < n && sortedIntervals[i][0] <= q) {
                const start = sortedIntervals[i][0];
                const end = sortedIntervals[i++][1];
                pq.offer([end - start + 1, end]);
            }

            while (!pq.isEmpty() && pq.peek()[1] < q) {
                pq.poll();
            }

            result[q] = pq.isEmpty() ? -1 : pq.peek()[0];
        }

        const res = [];
        for (const query of queries) {
            res.push(result[query]);
        }

        return res;
    }

// PriorityQueue implementation
class priorityQueue {
    constructor(comp) {
        this.comp = comp;
        this.heap = [];
    }

    offer(item) {
        this.heap.push(item);
        this._heapifyUp();
    }

    poll() {
        if (this.heap.length === 0) {
            return null;
        }

        const top = this.heap[0];
        const last = this.heap.pop();

        if (this.heap.length > 0) {
            this.heap[0] = last;
            this._heapifyDown();
        }

        return top;
    }

    peek() {
        return this.heap[0];
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    _heapifyUp() {
        let index = this.heap.length - 1;
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            if (this.comp.compare(this.heap[index], this.heap[parentIndex]) >= 0) {
                break;
            }
            this._swap(index, parentIndex);
            index = parentIndex;
        }
    }

    _heapifyDown() {
        let index = 0;
        const lastIndex = this.heap.length - 1;

        while (true) {
            let leftChild = index * 2 + 1;
            let rightChild = index * 2 + 2;
            let smallest = index;

            if (leftChild <= lastIndex && this.comp.compare(this.heap[leftChild], this.heap[smallest]) < 0) {
                smallest = leftChild;
            }
            if (rightChild <= lastIndex && this.comp.compare(this.heap[rightChild], this.heap[smallest]) < 0) {
                smallest = rightChild;
            }

            if (smallest === index) {
                break;
            }

            this._swap(index, smallest);
            index = smallest;
        }
    }

    _swap(i, j) {
        const temp = this.heap[i];
        this.heap[i] = this.heap[j];
        this.heap[j] = temp;
    }
}
