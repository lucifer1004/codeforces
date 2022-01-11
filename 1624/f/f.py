from sys import stdin, stdout
input = stdin.readline
flush = stdout.flush


def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


class Solution:
    def guess(self, num):
        print(f'! {num}')
        flush()

    def assign(self, c):
        print(f'+ {c}')
        flush()
        self.acc += c
        return read_int()

    def solve(self):
        n = read_int()
        step = 1
        while step * 2 < n:
            step *= 2
        self.acc = 0
        extra = 0
        last = 0
        changed = False

        while step > 0:
            ret = self.assign(step + extra)
            if ret == last:
                extra = 0
            else:
                extra = n - step
            step >>= 1
            changed = ret != last
            last = ret

        if changed:
            self.guess(last * n)
        else:
            self.guess(n * (last + 1) - 1)


Solution().solve()
