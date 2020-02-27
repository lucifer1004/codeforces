x1, y1, x2, y2 = map(int, input().split(' '))
x2 -= x1 - 1
y2 -= y1 - 1
x1 = 1
y1 = 1
xo = (x2 - x1 + 1) // 2 + (1 if abs(x1) % 2 == 1 and abs(x2) % 2 == 1 else 0)
xe = (x2 - x1 + 1) // 2 + (1 if abs(x1) % 2 == 0 and abs(x2) % 2 == 0 else 0)
yo = (y2 - y1 + 1) // 2 + (1 if abs(y1) % 2 == 1 and abs(y2) % 2 == 1 else 0)
ye = (y2 - y1 + 1) // 2 + (1 if abs(y1) % 2 == 0 and abs(y2) % 2 == 0 else 0)
print(xo * yo + xe * ye)
