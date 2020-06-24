n = int(input())
if n % 2 == 0:
    print('NO')
else:
    print('YES')
    ans = [0] * 2 * n
    for i in range(n):
        ans[i] = i * 2 + (2 if i % 2 == 1 else 1)
        ans[i + n] = i * 2 + (1 if i % 2 == 1 else 2)
    print(' '.join(map(str, ans)))
