n = int(input())
a = list(map(int, input().split(' ')))
ans = 1
length = 2
while length <= n:
    for i in range(0, n // length):
        b = a[i * length: (i + 1) * length]
        ok = True
        for j in range(len(b) - 1):
            if b[j] > b[j + 1]:
                ok = False
                break
        if ok:
            ans = length
            break
    length *= 2
print(ans)
