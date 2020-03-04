n, m, p = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
i = 0
while a[i] % p == 0:
    i += 1
j = 0
while b[j] % p == 0:
    j += 1
print(i + j)
