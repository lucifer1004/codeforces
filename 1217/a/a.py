t = int(input())
for case_num in range(t):
    a, b, c = map(int, input().split(' '))
    ans = c - (b - a + c) // 2
    print(max(min(ans, c + 1), 0))
