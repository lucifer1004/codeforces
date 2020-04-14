t = int(input())
r = 'abcdefghijklmnopqrstuvwxyz'
for case_num in range(t):
    n, a, b = map(int, input().split(' '))
    if b == 1:
        print(''.join(['a' for i in range(n)]))
    else:
        s = r[:(b-1)]
        for i in range(a - b + 1):
            s += r[b-1]
        ans = ''
        while len(ans) < n:
            ans += s
        print(ans[:n])
