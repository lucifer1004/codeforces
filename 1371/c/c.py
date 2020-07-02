def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    a, b, n, m = read_ints()
    if m <= min(a, b):
        print('Yes' if n + m <= a + b else 'No')
        continue
    if a > b:
        eat = min(n, a - b)
        n -= eat
        a -= eat
    elif a < b:
        eat = min(n, b - a)
        n -= eat
        b -= eat
    if n > 0:
        b -= (n + 1) // 2
        a -= n // 2
    print('Yes' if m <= min(a, b) else 'No')
