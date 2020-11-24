t = int(input())
for case_num in range(t):
    n = int(input())
    print(' '.join([str((i + 1) % n + 1) for i in range(n)]))
