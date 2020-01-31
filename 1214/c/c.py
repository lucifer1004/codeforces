n = int(input())
s = input()
left = 0
depth = 0
used = False
ok = True
for c in s:
    if c == '(':
        left += 1
        depth += 1
    else:
        depth -= 1
        if depth == -1 and not used:
            depth = 0
            used = True
        if depth < 0 and used:
            print('No')
            ok = False
            break

if ok:
    if left == n - left:
        print('Yes')
    else:
        print('No')
