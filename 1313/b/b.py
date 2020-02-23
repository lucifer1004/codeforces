t = int(input())
for case_num in range(t):
    n, x, y = map(int, input().split(' '))
    best = 1
    if x + y > n:
        best = min(x + y - n + 1, n)
    worst = min(x + y - 1, n)
    print(best, worst)
