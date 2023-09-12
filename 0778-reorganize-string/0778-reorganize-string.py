class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        max_heap = []
        for i, count in count.items():
            heapq.heappush(max_heap,(-count,i))
        heapq.heapify(max_heap)
        previous = None
        result = []
        while max_heap:
            k,c = heapq.heappop(max_heap)
            k += 1
            result.append(c)
            if previous and previous[0] < 0:
                heapq.heappush(max_heap,previous)
            previous = (k,c)
        return "".join(result) if len(s) == len(result) else ""
            