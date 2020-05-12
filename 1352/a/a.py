def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    ans = []
    s = str(n)
    l = len(s)
    for i in range(l):
        if s[-i-1] != '0':
            ans.append(int(s[-i-1]) * (10 ** i))
    print(len(ans))
    print(' '.join(map(str, ans)))
