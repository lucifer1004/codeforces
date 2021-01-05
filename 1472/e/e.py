def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    people = []
    for i in range(n):
        h, w = read_ints()
        people.append((h, w, i))
        people.append((w, h, i))
    ans = [-1] * n
    people.sort()
    lo = int(1e10)
    idx = -1
    l = -1
    for h, w, i in people:
        while l + 1 < n and people[l + 1][0] < h:
            l += 1
            if people[l][1] < lo:
                lo = people[l][1]
                idx = people[l][2]
        if lo < w:
            ans[i] = idx + 1
    print(' '.join(map(str, ans)))
