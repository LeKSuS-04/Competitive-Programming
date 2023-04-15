''' B - Coloring Matrix '''
# https://atcoder.jp/contests/abc298/tasks/abc298_b
# Date: 2023-14-15 15:06:08
# Run time: 32 ms
# Memory: 9376 KB
# Verdict: AC

n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]

def rotate():
    global A
    An = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            An[i][j] = A[n - 1 - j][i]
    A = An

def ok():
    for ar, br in zip(A, B):
        for ai, bi in zip(ar, br):
            if ai == 1 and bi != 1:
                return False
    return True

answ = ok()
rotate()
answ |= ok()
rotate()
answ |= ok()
rotate()
answ |= ok()
print('Yes' if answ else 'No')