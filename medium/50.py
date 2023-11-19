class Solution:
    def myPow(self, x: float, n: int) -> float:
        cn = abs(n)
        multiplier = x if n >=0 else 1.0/x
        cx = multiplier
        result = 1
        while cn >= 1:
            print(cn)
            if cn%2==1:
                result *= cx
            cn //= 2
            cx *= cx
        return result

print(Solution().myPow(2.0, -2))
