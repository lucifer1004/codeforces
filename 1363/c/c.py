def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


A_WIN = 'Ayush'
B_WIN = 'Ashish'
t = read_int()
for case_num in range(t):
    n, x = read_ints()
    adj = [[] for i in range(n + 1)]
    degree = [0 for i in range(n + 1)]
    for i in range(n - 1):
        u, v = read_ints()
        degree[u] += 1
        degree[v] += 1
    if degree[x] <= 1:
        print(A_WIN)
    else:
        print(A_WIN if n % 2 == 0 else B_WIN)
