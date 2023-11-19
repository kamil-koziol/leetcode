from re import L
from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        duplicated = set()

        for num in nums:
            if num in duplicated:
                return True

            duplicated.add(num)
        return False
