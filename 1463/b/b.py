def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    s = sum(a)
    odd = [a[i] if i % 2 == 1 else 1 for i in range(n)]
    if sum(abs(odd[i] - a[i]) for i in range(n)) * 2 <= s:
        print(' '.join(map(str, odd)))
        continue
    even = [a[i] if i % 2 == 0 else 1 for i in range(n)]
    print(' '.join(map(str, even)))
