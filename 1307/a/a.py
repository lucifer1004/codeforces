t = int(input())
for case_num in range(t):
    n, d = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    for i in range(1, n):
        can_move = min(d // i, a[i])
        d -= can_move * i
        a[0] += can_move
        if d <= 0:
            break
    print(a[0])
