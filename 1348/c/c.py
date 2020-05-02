from collections import Counter

def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n, k = read_ints()
    s = input()
    s = [c for c in s]
    s.sort()
    cnt = Counter(s)
    l = list(cnt)
    l.sort()
    if cnt[l[0]] < k:
        print(s[k - 1])
    else:
        if len(l) == 1:
            add = 0 if cnt[l[0]] % k == 0 else 1
            ans = l[0] * (n // k + add)
            print(ans)
        elif cnt[l[0]] == k and len(l) == 2:
            add = 0 if cnt[l[1]] % k == 0 else 1
            ans = l[0] + (l[1] * (n // k + add - 1))
            print(ans)
        else:
            print(l[0] + ''.join(s[k:]))