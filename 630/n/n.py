a, b, c = map(int, input().split(' '))
delta = b * b - 4 * a * c
x1 = (-b + delta ** 0.5) / a / 2
x2 = (-b - delta ** 0.5) / a / 2
output = '{:.15f}\n{:.15f}'
if x1 > x2:
    print(output.format(x1, x2))
else:
    print(output.format(x2, x1))
