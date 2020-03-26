t = int(input())
for i in range(t):
    n, k = map(int, input().split(' '))
    lo = k ** 2
    print('NO' if n < lo or n % 2 != k % 2 else 'YES')
