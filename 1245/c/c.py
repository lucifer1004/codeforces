s = input()
ch = '#'
count = 0
ans = 1
mod = 1000000007
f = [1, 1, 2]
for i in range(3, 100001):
    f.append((f[-1] + f[-2]) % mod)
s += '$'
ok = True
for i in range(len(s)):
    if s[i] == 'm' or s[i] == 'w':
        print(0)
        ok = False
        break
    if s[i] == ch:
        count += 1
    else:
        if ch == 'n' or ch == 'u':
            ans = ans * f[count] % mod
        ch = s[i]
        count = 1
if ok:
    print(ans)
