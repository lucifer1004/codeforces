from sys import stdin
def input(): return stdin.readline().strip()


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


t = read_int()
for case_num in range(t):
    s = list(map(lambda x: ord(x) - ord('a') + 1, input()))
    n = len(s)
    p = read_int()
    now = sum(s)
    order = list(range(n))
    order.sort(key=lambda x: -s[x])
    ptr = 0
    deleted = set()
    while now > p:
        now -= s[order[ptr]]
        deleted.add(order[ptr])
        ptr += 1
    ans = ''.join(chr(s[i] + ord('a') - 1)
                  for i in range(n) if i not in deleted)
    print(ans)
