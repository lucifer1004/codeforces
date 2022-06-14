from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = list(read_ints())
    cnt = [0] * 10
    for ai in a:
        cnt[ai % 10] += 1
    found = False
    for i in range(10):
        for j in range(10):
            k = (23 - i - j) % 10
            d = [0] * 10
            d[i] += 1
            d[j] += 1
            d[k] += 1
            if d[i] > cnt[i] or d[j] > cnt[j] or d[k] > cnt[k]:
                continue
            found = True
            break
        if found:
            break
    print('YES' if found else 'NO')
