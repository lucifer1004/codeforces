n = int(input())
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
ABC = round((a[1] * a[2] * b[2]) ** 0.5)
A = ABC // b[2]
ans = [A]
for i in range(1, n):
    ans.append(a[i] // A)
print(' '.join(map(str, ans)))
