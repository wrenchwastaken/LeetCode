class Solution:
    def frequencySort(self, s: str) -> str:
        count = Counter(s)
        max_heap = []
        for i,count in count.items():
            heapq.heappush(max_heap,(-count,i))
        heapq.heapify(max_heap)
        result = ""
        while max_heap:
            c,a = heapq.heappop(max_heap)
            c = -c
            for i in range(c):
                result = result+a
        return result