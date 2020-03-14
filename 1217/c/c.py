t = int(input())
for case_num in range(t):
    s = input()
    sum = [0]
    for i in s:
        sum.append(sum[-1] + int(i))
    ans = 0
    for i in range(len(s)):
        if s[i] == '1':
            ans += 1
            curr = 1
            j = i + 1
            while j < len(s):
                curr = curr * 2 + int(s[j])
                if curr > j + 1:
                    break
                right = j - i + 1
                left = curr - right
                if i >= left and sum[i] == sum[i - left]:
                    ans += 1
                else:
                    break
                j += 1
    print(ans)
