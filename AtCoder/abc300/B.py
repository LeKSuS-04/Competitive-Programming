''' B - Same Map in the RPG World '''
# https://atcoder.jp/contests/abc300/tasks/abc300_b
# Date: 2023-04-29 16:47:57
# Run time: 98 ms
# Memory: 9116 KB
# Verdict: AC (After contest)

h, w = map(int, input().split())

def vshift(A, x: int):
    Anew = [[' '] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            Anew[i][j] = A[(i + x) % h][j]
    return [''.join(r) for r in Anew]

def hshift(A, x: int):
    Anew = [[' '] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            Anew[i][j] = A[i][(j + x) % w]
    return [''.join(r) for r in Anew]

a = [input() for _ in range(h)]
b = [input() for _ in range(h)]

def solve():
    for s in range(h):
        for t in range(w):
            if vshift(hshift(a, t), s) == b:
                print('Yes')
                return
    print('No')

solve()