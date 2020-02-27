def c(n, k):
    ans = 1
    for i in range(k):
        ans *= n - i
    for i in range(k):
        ans //= i + 1
    return ans


n = int(input())
print(120 * c(n, 5) * c(n, 5))
