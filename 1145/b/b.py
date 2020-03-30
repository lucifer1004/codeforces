n0 = input()
n = int(n0)
print('NO' if ('1' in n0 and n != 12) or '7' in n0 or '9' in n0 or (
    n >= 10 and n <= 29 and n != 12) else 'YES')
