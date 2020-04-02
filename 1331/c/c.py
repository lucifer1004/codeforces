a = int(input())
s = '{:06b}'.format(a)
t = s[0] + s[5] + s[3] + s[2] + s[4] + s[1]
print(int(t, 2))