t = int(input())
for case_num in range(t):
    a, b = map(int, input().split(' '))
    print((b - a % b) % b)
