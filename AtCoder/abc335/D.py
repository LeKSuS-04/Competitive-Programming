class Dir:
    L = 0
    R = 1
    U = 2
    D = 3

n = int(input())
m = [['0'] * n for _ in range(n)]
m[n // 2][n // 2] = 'T'
x, y = 0, 0
dir = Dir.R
le = 0
re = n - 1
ue = 1
de = n - 1

for i in range(n**2 - 1):
    m[y][x] = str(i + 1)
    if dir == Dir.R:
        x += 1
        if x == re:
            dir = Dir.D
            re -= 1
    elif dir == Dir.D:
        y += 1
        if y == de:
            dir = Dir.L
            de -= 1
    elif dir == Dir.L:
        x -= 1
        if x == le:
            dir = Dir.U
            le += 1
    elif dir == Dir.U:
        y -= 1
        if y == ue:
            dir = Dir.R
            ue += 1

for line in m:
    print(*line)
