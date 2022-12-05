n = int(input())
dp = [0] * (n + 2)
mp = {}

for i in range(n):
    s = input().split()
    x = int(s[1])
    if s[0] == 'win':
        mp[x] = i
    else:
        if x in mp:
            dp[i] = max(dp[i], dp[mp[x]] + 2**x)

    dp[i+1] = dp[i]

print(dp[n])

