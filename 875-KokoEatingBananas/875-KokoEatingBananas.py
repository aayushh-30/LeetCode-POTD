from math import ceil
from typing import List

class Solution:
    def canKokoEat(self, mid: int, piles: List[int], h: int) -> bool:
        hour = 0
        for i in piles:
            time = ceil(i / mid)
            hour += time
        return hour <= h

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        start = 1
        end = max(piles)
        ans = end

        while start <= end:
            mid = start + (end - start) // 2
            if self.canKokoEat(mid, piles, h):
                ans = mid
                end = mid - 1
            else:
                start = mid + 1

        return ans
