def read_ints():
    return map(int, input().split(' '))


def binary_search(a, x):
    l = 0
    r = len(a) - 1
    while l <= r:
        mid = (l + r) // 2
        if a[mid] == x:
            print('YES')
            return
        if a[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    print('NO')


n, k = read_ints()
a = list(read_ints())
q = read_ints()
for i in q:
    binary_search(a, i)
