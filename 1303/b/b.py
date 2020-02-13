t = int(input())
for case_num in range(t):
    n, g, b = map(int, input().split(' '))
    if g >= n:
        print(n)
    else:
        target = (n + 1) // 2
        cycle = (target - 1) // g
        ans = cycle * b + target
        print(max(ans, n))
