s = input()
a = s.split('@')
n = len(a)
valid = True
if n == 1:
    valid = False
username = []
host = []
for i in range(n):
    if len(a[i]) == 0:
        valid = False
        break
    if i == 0:
        username.append(a[i])
    elif i == n - 1:
        host.append(a[i])
    else:
        if len(a[i]) < 2:
            valid = False
            break
        host.append(a[i][0])
        username.append(a[i][1:])
if not valid:
    print('No solution')
else:
    emails = [username[i] + '@' + host[i] for i in range(n - 1)]
    print(','.join(emails))
