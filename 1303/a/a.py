t = int(input())
for case_num in range(t):
    s = input()
    a = []
    for i in range(len(s)):
        if s[i] == '1':
            a.append(i)
    if len(a) > 1:
        print(a[-1] - a[0] + 1 - len(a))
    else:
        print(0)
