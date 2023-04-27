# Verdict: AC

n = int(input())

dp = [[0] * 25 for _ in range(120)]
dp[2][1] = 1
for t in range(1, len(dp) - 1):
    for l in range(1, len(dp[t]) - 1):
        dp[t + 1][l + 1] += dp[t][l]
        if l >= 3 and l < 20:
            dp[t + 1][1] += dp[t][l]
print(sum(dp[n][:20]))
