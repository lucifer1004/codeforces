def solve(n):
    s = set()
    for i in range(0, n + 1):
        for v in range(0, n - i + 1):
            for x in range(0, n - i - v + 1):
                l = n - i - v - x
                s.add(i + v * 5 + x * 10 + l * 50)
    return len(s)


n = int(input())
if n < 11:
    print(solve(n))
else:
    print(49 * n - 247)
