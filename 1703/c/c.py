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
    for i in range(n):
        p, s = input().split()
        for op in s[::-1]:
            if op == 'U':
                a[i] -= 1
                if a[i] < 0:
                    a[i] = 9
            else:
                a[i] += 1
                if a[i] > 9:
                    a[i] = 0
    print(' '.join(map(str, a)))
