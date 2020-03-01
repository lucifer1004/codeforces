def check(n):
    digit = 0
    numbers = set()
    while n > 0:
        digit += 1
        numbers.add(n % 10)
        n //= 10
    return digit == len(numbers)


l, r = map(int, input().split(' '))
found = False
for i in range(l, r + 1):
    if check(i):
        print(i)
        found = True
        break
if not found:
    print(-1)
