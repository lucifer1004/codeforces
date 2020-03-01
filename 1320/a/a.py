n = int(input())
a = list(map(int, input().split(' ')))
sum = dict()
for i in range(n):
    group = a[i] - i
    if group in sum:
        sum[group] += a[i]
    else:
        sum[group] = a[i]
print(max(sum.values()))
