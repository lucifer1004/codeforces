from collections import Counter

n = int(input())
a = list(map(int, input().split(' ')))
counter = Counter(a)
extra = 0
for i in counter:
    extra += counter[i] - 1
if extra <= 1:
    print('NO')
else:
    b = [(a[i], i + 1) for i in range(n)]
    b.sort()
    print('YES')
    x = [b[i][1] for i in range(n)]
    print(' '.join(map(str, x)))
    times = 0
    for i in range(n - 1):
        if b[i][0] == b[i + 1][0]:
            tmp = b[i]
            b[i] = b[i + 1]
            b[i + 1] = tmp
            times += 1
            x = [b[j][1] for j in range(n)]
            print(' '.join(map(str, x)))
        if times == 2:
            break
