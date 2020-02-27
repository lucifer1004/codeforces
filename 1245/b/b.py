t = int(input())
for case_num in range(t):
    n = int(input())
    a, b, c = map(int, input().split(' '))
    s = input()
    win = 0
    t = ['' for i in s]
    for i in range(len(s)):
        if s[i] == 'R' and b > 0:
            t[i] = 'P'
            b -= 1
            win += 1
        if s[i] == 'P' and c > 0:
            t[i] = 'S'
            c -= 1
            win += 1
        if s[i] == 'S' and a > 0:
            t[i] = 'R'
            a -= 1
            win += 1
    if win < (n + 1) // 2:
        print('NO')
    else:
        for i in range(len(s)):
            if t[i] == '':
                if a > 0:
                    t[i] = 'R'
                    a -= 1
                else:
                    if b > 0:
                        t[i] = 'P'
                        b -= 1
                    else:
                        if c > 0:
                            t[i] = 'S'
                            c -= 1
        print('YES')
        print(''.join(t))
