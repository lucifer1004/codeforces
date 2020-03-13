t = int(input())
for case_num in range(t):
    s = input()
    s2 = 'R' + s + 'R'
    a = []
    for i in range(len(s2)):
        if s2[i] == 'R':
            a.append(i)
    ans = 1
    for i in range(len(a) - 1):
        ans = max(ans, a[i + 1] - a[i])
    print(ans)
