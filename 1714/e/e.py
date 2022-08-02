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
    zero = set()
    mod20 = set()
    for ai in a:
        if ai % 10 == 5:
            zero.add(ai + 5)
        elif ai % 10 == 0:
            zero.add(ai)
        else:
            kk = ai % 20
            ks = set()
            ks.add(kk)
            while (kk + (kk % 10)) % 20 not in ks:
                kk = (kk + (kk % 10)) % 20
                ks.add(kk)
            if 2 in ks:
                mod20.add(2)
            elif 12 in ks:
                mod20.add(12)

    if len(mod20) + len(zero) == 1:
        print('Yes')
    else:
        print('No')
