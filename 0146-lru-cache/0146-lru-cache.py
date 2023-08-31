class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity 
        self.cache = OrderedDict() 

    def get(self, key: int) -> int:
        if key not in self.cache: 
            return -1 
        self.cache.move_to_end(key) 
        return self.cache[key] 

    def put(self, key: int, value: int) -> None:
        if key in self.cache: 
            del self.cache[key] 
        elif len(self.cache) == self.capacity: 
            self.cache.popitem(last=False) 
        self.cache[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)