class MinHeap {
    constructor(size) {
        this.size = size || null;
        this.heap = [];
    }

    insert(value) {
        this.heap.push(value);

        let currentIndex = this.heap.length - 1;

        this.bubbleUp(currentIndex);

        if (this.size && this.heap.length > this.size) {
            this.removeMin();
        }
    }

    swap(a, b) {
        let temp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = temp;
    }

    bubbleUp(index) {
        while (this.heap[this.parent(index)] && this.heap[this.parent(index)][1] > this.heap[index][1]) {
            this.swap(this.parent(index), index);
            index = this.parent(index);
        }
    }

    heapify(index) {
        while (true) {
            let left = this.left(index),
                right = this.right(index);

            if (this.heap[left] && this.heap[right] && this.heap[left][1] < this.heap[right][1] && this.heap[index][1] > this.heap[left][1]) {
                this.swap(left, index);
                index = left;
            } else if (this.heap[left] && this.heap[right] && this.heap[right][1] < this.heap[left][1] && this.heap[index][1] > this.heap[right][1]) {
                this.swap(right, index);
                index = right;
            } else if (this.heap[left] && this.heap[index][1] > this.heap[left][1]) {
                this.swap(left, index);
                index = left;
            } else if (this.heap[right] && this.heap[index][1] > this.heap[right][1]){
                this.swap(right, index);
                index = right;
            } else {
                break;
            }
        }
    }

    removeMin() {
        this.swap(0, this.heap.length - 1);
        this.heap.pop();
        this.heapify(0);
    }

    parent(index) {
        return Math.floor((index - 1) / 2);
    }

    left(index) {
        return 2 * index + 1;
    }

    right(index) {
        return 2 * index + 2;
    }
}

var topKFrequent = function(nums, k) {
    let heap = new MinHeap(k),
        hash = {},
        output = [];
    
    // Get frequency
    nums.forEach((num) => {
        if (!(num in hash)) hash[num] = 0;
        hash[num] ++;
    });
    
    let keys = Object.keys(hash);
    
    for (var i = 0; i <= keys.length -1; i ++) {
        let key = keys[i];
        
        output.push([key, hash[key]]); // key, frequency
    }

    output.forEach(value => {
        heap.insert(value);
    });

    return heap.heap.map((val) => Number(val[0]));
};