from collections import deque

def read_int():
    return int(input())


def read_ints():
    return map(int, input().split(' '))


t = read_int()
for case_num in range(t):
    n = read_int()
    day = 0
    num = 1
    weight = 1
    history = []
    while weight < n:
        day += 1
        delta = n - weight
        if num <= delta <= 2 * num:
            history.append(delta - num)
            weight = n
        elif delta > 2 * num:
            history.append(num)
            num *= 2
            weight += num
        else:
            history.pop()
            k = min(delta // 2, num // 2)
            p = delta - 2 * k
            history.append(k)
            history.append(p)
            weight = n  
        if weight == n:
            break
    print(day)
    print(' '.join(map(str, history)))