''' 1809C. Sum on Subarrays '''
# https://codeforces.com/contest/1809/problem/C
# Date: Mar/23/2023 18:36
# Run time: 218 ms
# Memory: 8916 KB
# Verdict: AC

C = [[0 for _ in range(40)] for _ in range(40)]
FACT = [0 for _ in range(40)]
FACT[0] = FACT[1] = 1
for i in range(2, 40):
    FACT[i] = i * FACT[i - 1]
for n in range(0, 40):
    for k in range(0, (n + 1) // 2 + 1):
        C[k][n] = C[n - k][n] = FACT[n] // FACT[k] // FACT[n - k]

TC = int(input())
for _ in range(TC):
    n, k = map(int, input().split())
    a = 1000
    b = -999
    affected = set()
    for i in range(n, 0, -1):
        if k >= i:
            k -= i
            affected.add(i)

    s = 1
    arr = [0] * n
    for i in range(1, n + 1):
        if i not in affected and i - 1 not in affected:
            arr[i-1] = -1
            s += 1
        elif i in affected:
            if s + 1 == 0:
                s += 1
            arr[i-1] = s
        else:
            arr[i-1] = -s - 1
            s = abs(s) + 2
    print(*arr)