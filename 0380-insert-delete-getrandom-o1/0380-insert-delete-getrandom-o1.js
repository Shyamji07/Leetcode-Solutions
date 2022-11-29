class RandomizedSet:

    def __init__(self):
        self.mapp = {}
        self.count = 0

    def insert(self, val: int) -> bool:
        if self.mapp.get(val) is None:
            self.mapp[val] = 1
            return True
        return False 

    def remove(self, val: int) -> bool:
        if self.mapp.get(val) is not None:
            self.mapp.pop(val)
            return True
        return False

    def getRandom(self) -> int:
        ran = [i for i in self.mapp.keys()]
        return random.choice(ran)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()