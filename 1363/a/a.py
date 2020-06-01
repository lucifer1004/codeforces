def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, x = read_ints()
    a = list(read_ints())
    even = 0
    for i in a:
        if i % 2 == 0:
            even += 1
    odd = n - even
    print('Yes' if odd > 0 and even >= x -
          min(x - (1 - x % 2), odd - (1 - odd % 2)) else 'No')
