import collections
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)

        def get_key(arr: List[int]) -> str:
            full_str = "" 
            for num in arr:
                full_str += f"{num}#"
            return full_str


        for s in strs:
            count = [0] * 26

            for c in s:
                count[ord(c) - ord('a')] += 1

            ans[get_key(count)].append(s)

        return ans.values()


