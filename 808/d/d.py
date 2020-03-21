from collections import Counter

n = int(input())
a = list(map(int, input().split(' ')))
total = sum(a)
if total % 2 == 1:
    print('NO')
else:
    target = total // 2
    left = 0
    to_add = Counter(a)
    to_del = Counter([])
    found = False
    for i in range(n):
        if left < target:
            need = target - left
            if need in to_add:
                found = True
                break
        if left == target:
            found = True
            break
        if left > target:
            extra = left - target
            if extra in to_del:
                found = True
                break
        to_add[a[i]] -= 1
        if to_add[a[i]] == 0:
            del to_add[a[i]]
        if not a[i] in to_del:
            to_del[a[i]] = 1
        else:
            to_del[a[i]] += 1
        left += a[i]
    print('YES' if found else 'NO')
