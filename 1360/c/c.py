def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    cnt = [0 for i in range(101)]
    even = 0
    for ai in a:
        cnt[ai] += 1
        if ai % 2 == 0:
            even += 1
    odd = n - even
    if even % 2 == 0:
        print('YES')
    else:
        ok = False
        for i in range(1, 100):
            if cnt[i] > 0 and cnt[i + 1] > 0:
                ok = True
                break
        print('YES' if ok else 'NO')
