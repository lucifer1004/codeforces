def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    d = dict()
    for i, a in enumerate(read_ints()):
        if a not in d:
            d[a] = []
        d[a].append(i + 1)
    if len(d) == 1:
        print('NO')
        continue
    print('YES')
    groups = list(d.values())
    for i in groups[0]:
        print(i, groups[1][0])
    for i in groups[1][1:]:
        print(groups[0][0], i)
    for g in range(2, len(groups)):
        for i in groups[g]:
            print(groups[0][0], i)
