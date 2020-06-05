def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


from collections import Counter
t = read_int()
for case_num in range(t):
    n = read_int()
    s = list(read_ints())
    cs = Counter(s)
    found = False
    for i in range(1, 1024):
        a = [si ^ i for si in s]
        ca = Counter(a)
        if ca == cs:
            print(i)
            found = True
            break
    if not found:
        print(-1)
