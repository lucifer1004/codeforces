from cmath import pi, exp


def FFT(a, w):
    length = len(a)

    if length == 1:
        return [a[0]]

    a_even = []
    a_odd = []
    for i in range(0, length // 2):
        a_even.append(a[2 * i])
        a_odd.append(a[2 * i + 1])
    f_even = FFT(a_even, w ** 2)
    f_odd = FFT(a_odd, w ** 2)
    x = 1
    values = [0 for i in range(length)]
    for i in range(0, length // 2):
        values[i] = f_even[i] + x * f_odd[i]
        values[i + length // 2] = f_even[i] - x * f_odd[i]
        x = x * w
    return values


def mul(a, b):
    length = len(a) + len(b) - 1
    n = 1
    while 2 ** n < length:
        n += 1
    length = 2 ** n
    a.extend([0 for i in range(length - len(a))])
    b.extend([0 for i in range(length - len(b))])

    w = exp(2 * pi * 1j / length)
    a_val = FFT(a, w)
    b_val = FFT(b, w)
    c_val = [a_val[i] * b_val[i] for i in range(length)]
    result = [round((x / length).real) for x in FFT(c_val, w ** -1)]

    while result[-1] == 0:
        del result[-1]
    return result


n, m, p = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
c = mul(a, b)
for i in range(len(c)):
    if c[i] % p != 0:
        print(i)
        break
