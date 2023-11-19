from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = dict()

        for i, num in enumerate(nums):
            ans = seen.get(target - num)
            if ans is not None:
                return [ans, i]

            seen[num] = i
        return []


testcases = [
    {
        "input": ([2,7,11,15], 9),
        "output": [0,1]
    },
    {
        "input": ([3,2,4], 6),
        "output": [1,2]
    },
    {
        "input": ([3,3], 6),
        "output": [0,1]
    },
]

solution = Solution()
for i, case in enumerate(testcases):
    result = solution.twoSum(*case["input"])

    if result == case["output"]:
        print(f"{i+1:02}. OK")
    else:
        print(f"{i+1:02}. Expected: {case['output']}\nGot: {result}")


