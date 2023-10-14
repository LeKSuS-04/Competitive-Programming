# Verdict: AC
n = int(input())
ansmax = 25 + 25 + n - 1
ansmin = max(n, 25) + 25
print(ansmin, ansmax)