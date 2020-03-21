n, k = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = [0]
for i in range(n):
    b.append(b[-1] + a[i])
weeks = n - k + 1
sum = 0
for i in range(weeks):
    sum += b[i + k] - b[i]
print('{:.10f}'.format(sum / weeks))
