from collections import Counter

a = Counter(input().split(' '))
legs = False
for num in a:
    if a[num] >= 4:
        a[num] -= 4
        if a[num] == 0:
            del a[num]
        legs = True
        break
if not legs:
    print('Alien')
else:
    b = list(a)
    print('Elephant' if len(b) == 1 else 'Bear')
