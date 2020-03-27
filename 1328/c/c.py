t = int(input())
for case_num in range(t):
    n = int(input())
    x = input()
    a = []
    b = []
    split = False
    for i in x:
        if not split:
            if i == '2':
                a.append('1')
                b.append('1')
            if i == '0':
                a.append('0')
                b.append('0')
            if i == '1':
                a.append('1')
                b.append('0')
                split = True
        else:
            a.append('0')
            b.append(i)
    print(''.join(a))
    print(''.join(b))
