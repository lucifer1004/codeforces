t = int(input())
for case_num in range(t):
    n = int(input())
    if n == 1:
        print(-1)
    else:
        a = [2 if i == 0 else 3 for i in range(n)]
        print(''.join(map(str, a)))
