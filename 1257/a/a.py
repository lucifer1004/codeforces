t = int(input())
for case_num in range(t):
    n, x, a, b = map(int, input().split(' '))
    print(min(abs(a - b) + x, n - 1))
