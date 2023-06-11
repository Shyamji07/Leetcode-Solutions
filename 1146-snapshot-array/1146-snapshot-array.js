var SnapshotArray = function(length) {
    this.length = length;
    this.updated = true
    this.arr = {}
    this.snaps = [];
    this.snap_id = 0;
};

SnapshotArray.prototype.set = function(index, val) {
    if(val !== this.arr[index]) {
        this.arr[index] = val;
        this.updated = true;
    }
};
SnapshotArray.prototype.snap = function() {
    if(this.updated) {
        this.snaps[this.snap_id] = this.arr;
        this.arr = {...this.arr};
    } else {
        if(Number.isInteger(this.snaps[this.snap_id - 1])) {
            this.snaps[this.snap_id] = this.snaps[this.snap_id - 1];
        } else {
            this.snaps[this.snap_id] = this.snap_id - 1;
        }
    }
    this.updated = false;
    return this.snap_id++;
};
SnapshotArray.prototype.get = function(index, snap_id) {
    if(Number.isInteger(this.snaps[snap_id])) {
        return this.snaps[this.snaps[snap_id]][index] || 0;
    }
    return this.snaps[snap_id][index] || 0;
};