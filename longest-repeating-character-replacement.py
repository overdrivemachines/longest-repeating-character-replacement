class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        result = 0
        for i in range(len(s) - k):
            sub_length = 1
            j = i + 1
            while k > 0 and j < len(s):
                if s[j] != s[i]:
                    k -= 1
                j += 1
                sub_length += 1
                result = max(result, sub_length)
        return result


sol = Solution()
s, k = "AABABBA", 1  # output should be 4
print(sol.characterReplacement(s, k))
