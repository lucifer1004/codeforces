import re


def name_to_num(s):
    ans = 0
    for c in s:
        ans = ans * 26 + (ord(c) - ord('A')) + 1
    return ans


def num_to_name(n):
    s = ""
    while n > 0:
        rem = n % 26
        if rem == 0:
            rem = 26
        s = chr(ord('A') + rem - 1) + s
        n = (n - rem) // 26
    return s


n = int(input())
for i in range(n):
    s = input()
    x = re.match(r'R([0-9]+)C([0-9]+)', s)
    if x == None:
        x = re.match(r'([A-Z]+)([0-9]+)', s)
        col_name = x.group(1)
        row = x.group(2)
        col = name_to_num(col_name)
        print('R{}C{}'.format(row, col))
    else:
        row = x.group(1)
        col = int(x.group(2))
        col_name = num_to_name(col)
        print('{}{}'.format(col_name, row))
