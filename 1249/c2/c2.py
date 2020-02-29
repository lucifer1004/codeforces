t = int(input())
for case_num in range(t):
    n0 = int(input())
    n = n0
    a = []
    while n > 0:
        a.append(n % 3)
        n //= 3
    i = 0
    while i < len(a) and a[i] != 2:
        i += 1
    if i == len(a):
        print(n0)
    else:
        i = len(a) - 1
        while a[i] != 2:
            i -= 1
        for j in range(i):
            a[j] = 0
        while i < len(a) and a[i] == 2:
            if i == len(a) - 1:
                a.append(0)
            a[i] = 0
            a[i + 1] += 1
            i += 1
        ans = 0
        curr = 1
        for j in a:
            ans += curr * j
            curr *= 3
        print(ans)
