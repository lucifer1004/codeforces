n, m, k = map(int, input().split(' '))
path = []
symbols = 'ULRD'
for i in range(n):
    for j in range(m - 1):
        path.append(2 if i % 2 == 0 else 1)
    path.append(3)
reverse = [3 - i for i in path]
reverse.reverse()
path = path + reverse
print(len(path))
print(''.join(map(lambda x: symbols[x], path)))
