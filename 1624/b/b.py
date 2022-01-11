from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    a, b, c = read_ints()
    if (b * 2 - c > 0 and (b * 2 - c) % a == 0) or (b * 2 - a > 0 and (b * 2 - a) % c == 0) or ((a + c) % 2 == 0 and (a + c) // 2 % b == 0):
        print('YES')
    else:
        print('NO')
