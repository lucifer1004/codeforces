from functools import lru_cache


@lru_cache(maxsize=None)
def split(k, n):
    if n == 1:
        return 1
    ans = 0
    for i in range(k + 1):
        ans += split(i, n - 1)
    return ans


n = int(input())
print(split(5, n) * split(3, n))
