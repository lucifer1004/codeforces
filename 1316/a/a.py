t = int(input())
for case_num in range(t):
    n, m = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    sum = 0
    for i in a:
        sum += i
    print(min(m, sum))
