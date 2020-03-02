t = int(input())
for case_num in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    swap = 0
    swapped = True
    while swap < n:
        swapped = False
        mi = -1
        m = n + 1
        for i in range(swap, n):
            if a[i] < m:
                m = a[i]
                mi = i
        b = a.copy()
        b[swap] = m
        for j in range(swap + 1, mi + 1):
            swapped = True
            b[j] = a[j - 1]
        swap = mi if swapped else swap + 1
        a = b
    print(' '.join(map(str, a)))
