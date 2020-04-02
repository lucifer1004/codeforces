s = input()
e = 0
o = 0
for c in s:
    if c == 'E':
        e += 1
    if c == 'O':
        o += 1
print('YES' if abs(o - e) % 2 == 1 else 'NO')