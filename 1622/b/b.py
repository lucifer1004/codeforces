from sys import stdin
input = stdin.readline


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    p = list(read_ints())
    s = input()
    dislike = [(p[i], i) for i in range(n) if s[i] == '0']
    dislike.sort()
    like = [(p[i], i) for i in range(n) if s[i] == '1']
    like.sort()
    m = len(dislike)
    for j, (old_rating, i) in enumerate(dislike):
        p[i] = j + 1
    for j, (old_rating, i) in enumerate(like):
        p[i] = m + j + 1
    print(' '.join(map(str, p)))
