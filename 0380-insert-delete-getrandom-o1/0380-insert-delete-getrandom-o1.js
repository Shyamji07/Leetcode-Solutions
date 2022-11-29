var RandomizedSet = function() {
    this.arr = [];
    this.mapp = {};
};

/**
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
    if (val in this.mapp){
        return false;
    }

    this.arr.push(val);
    this.mapp[val] = this.arr.length - 1;
    return true;
};

/**
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
    if (!(val in this.mapp)){
        return false;
    }

    const i = this.mapp[val];
    delete this.mapp[val];

    if (i < this.arr.length - 1) {
        this.arr[i] = this.arr.slice(-1)[0];
        this.mapp[this.arr[i]] = i;
    }

    this.arr.pop();
    return true;
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
    return this.arr[Math.floor(Math.random() * this.arr.length)]
};


/** 
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */