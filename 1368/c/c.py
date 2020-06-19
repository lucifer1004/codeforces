def read_int():
    return int(input())


n = read_int()
a = [(i, i + 1) for i in range(n + 1)]
b = [(i, i) for i in range(n + 2)]
c = [(i + 1, i) for i in range(n + 1)]
s = a + b + c
print(len(s))
print('\n'.join(map(lambda x: str(x[0]) + " " + str(x[1]), s)))
