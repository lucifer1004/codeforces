def check(s):
    l = len(s)
    for i in range(l // 2):
        if s[i] != s[l - i - 1]:
            return False
    return True


def check_pair(s, t):
    l = len(s)
    for i in range(l):
        if s[i] != t[l - i - 1]:
            return False
    return True


n, m = map(int, input().split(' '))
s = []
for i in range(n):
    s.append(input())

mid = ""
left = []
used = [False for i in range(n)]
for i in range(n):
    if used[i]:
        continue
    formid = False
    if mid == "" and check(s[i]):
        formid = True
    for j in range(i + 1, n):
        if used[j]:
            continue
        if (check_pair(s[i], s[j])):
            left.append(s[i])
            used[j] = True
            formid = False
            break
    if formid:
        mid = s[i]
nl = len(left)
print(m * (nl * 2 + (0 if mid == "" else 1)))
left.append(mid)
for i in range(nl):
    left.append(left[nl - i - 1][::-1])
print("".join(left))
