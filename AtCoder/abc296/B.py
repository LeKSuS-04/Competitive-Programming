''' B - Chessboard '''
# https://atcoder.jp/contests/abc296/tasks/abc296_b
# Date: 2023-04-01 15:03:14
# Run time: 25 ms
# Memory: 8776 KB
# Verdict: AC

board = [input() for _ in range(8)]
numbers = '87654321'
letters = 'abcdefgh'

for i, r in enumerate(board):
    for j, c in enumerate(r):
        if c == '*':
            print(letters[j] + numbers[i])
            exit()
