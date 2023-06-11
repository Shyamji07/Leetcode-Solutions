class SnapshotArray {
    constructor(length) {
        // each element will be an array of Map
        this.elements = Array(length).fill(null).map(el => new Map());   // max O(n + s)
        this.snapId = 0;
    }
    set(index, val) {   // O(1)
        this.elements[index].set(this.snapId, val);
    }
    snap() {    // O(1)
        ++this.snapId;
        return this.snapId - 1;
    }
    get(index, snap_id) {   // O(log(s) + s)
        const element = Array.from(this.elements[index].keys());    // O(s)
        let left = 0,
            right = element.length - 1,
            mid, id = -1;
        
        while(left <= right) {
            mid = left + Math.floor((right - left) / 2);
            if(element[mid] <= snap_id) {
                id = element[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return id === -1 ? 0 : this.elements[index].get(id);
    }
}