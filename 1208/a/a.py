t = int(input())
for case_num in range(t):
    a, b, n = map(int, input().split(' '))
    print([a, b, a ^ b][n % 3])
