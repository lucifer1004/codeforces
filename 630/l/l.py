n = input()
m = [n[0], n[2], n[4], n[3], n[1]]
print('{:05d}'.format(int(''.join(m)) ** 5 % 100000))
