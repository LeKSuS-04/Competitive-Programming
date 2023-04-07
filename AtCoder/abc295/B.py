''' B - Bombs '''
# https://atcoder.jp/contests/abc295/tasks/abc295_b
# Date: 2023-03-25 15:08:42
# Run time: 48 ms
# Memory: 9664 KB
# Verdict: AC

r, c = map(int, input().split())
rows = [list(input()) for _ in range(r)]

for i1, row in enumerate(rows):
    for j1, is_wall in enumerate(row):
        for i2, row in enumerate(rows):
            for j2, number in enumerate(row):
                if (
                    is_wall == '#'
                    and number.isnumeric()
                    and abs(i1 - i2) + abs(j1 - j2) <= int(number)
                ):
                    rows[i1][j1] = '.'

for i, row in enumerate(rows):
    for j, cell in enumerate(row):
        if cell.isnumeric():
            rows[i][j] = '.'


for row in rows:
    print(''.join(row))
