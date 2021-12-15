from sys import stdin


def read_int():
    return int(stdin.readline())


def read_ints():
    return map(int, stdin.readline().split())


t = read_int()
for case_num in range(t):
    n = read_int()
    a = stdin.readline().split()
    ans = [a[0][0]]
    flag = False
    for i in range(n - 3):
        if a[i][1] == a[i + 1][0]:
            ans.append(a[i][1])
        else:
            flag = True
            ans.append(a[i][1])
            ans.append(a[i + 1][0])

    ans.append(a[-1][1])

    if not flag:
        ans.append(a[-1][1])

    print(''.join(ans))
