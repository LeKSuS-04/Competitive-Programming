''' D - Writing a Numeral '''
# https://atcoder.jp/contests/abc298/tasks/abc298_f
# Date: 2023-14-15 15:18:25
# Run time: 2014 ms
# Memory: 13588 KB
# Verdict: AC

q = int(input())
s = 1
m = 998244353
digits = [1]
i = 0
n = 0
for _ in range(q):
    cmd = input()
    if cmd[0] == '1':
        _, x = map(int, cmd.split())
        s = (s * 10 + x) % m
        n += 1
        digits.append(x)
    if cmd[0] == '2':
        s = (s - digits[i] * pow(10, n, m)) % m
        n -= 1
        i += 1
    if cmd[0] == '3':
        print(s)
    