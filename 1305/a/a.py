t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    b = list(map(int, input().split(' ')))
    a.sort()
    b.sort()
    print(' '.join(map(str, a)))
    print(' '.join(map(str, b)))
