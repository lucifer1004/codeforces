t = int(input())
for case_num in range(t):
    n = int(input())
    if n % 4 != 0:
        print("NO")
    else:
        ans = [i * 2 for i in range(1, n // 2 + 1)]
        for i in range(n // 2 - 1):
            ans.append(ans[i] - 1)
        ans.append(ans[n // 2 - 1] + n // 2 - 1)
        print("YES")
        print(" ".join(map(str, ans)))
