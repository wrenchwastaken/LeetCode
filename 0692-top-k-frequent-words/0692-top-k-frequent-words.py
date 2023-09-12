class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ez = {}
        result = []
        for i in words:
            ez[i] = ez.get(i,0) + 1
        max_heap = []
        for key,val in ez.items():
            heapq.heappush(max_heap,[-val,key])
        for j in range(k):
            val,key = heapq.heappop(max_heap)
            result.append(key)
        result.sort
        return result