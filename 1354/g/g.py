from random import randint


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


def query(a, b):
    print('? {} {}'.format(len(a), len(b)))
    print(' '.join(map(str, a)))
    print(' '.join(map(str, b)))
    return input()


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    found = False
    for i in range(30):
        b = randint(2, n)
        if query([1], [b]) == 'SECOND':
            print('! 1')
            found = True
            break
    if not found:
        length = 1
        a = list(range(1, length + 1))
        b = list(range(length + 1, 2 * length + 1))
        while query(a, b) == 'EQUAL':
            length *= 2
            if length * 2 > n:
                break
            a = list(range(1, length + 1))
            b = list(range(length + 1, 2 * length + 1))
        l, r = length + 1, min(2 * length, n)
        lo = l
        while l <= r:
            mid = (l + r) // 2
            a = list(range(1, mid - lo + 2))
            b = list(range(lo, mid + 1))
            result = query(a, b)
            if result == 'EQUAL':
                l = mid + 1
            else:
                r = mid - 1
        print('! {}'.format(l))
