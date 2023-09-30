# Verdict: TL

from copy import deepcopy
from itertools import permutations


matrix = [list(map(int, input().split())) for _ in range(3)]


def is_disappointed(matrix: list[list[int]]):
    triples = deepcopy(matrix)
    for i in range(3):
        triples.append([matrix[j][i] for j in range(3)])
    triples.append([matrix[0][0], matrix[1][1], matrix[2][2]])
    triples.append([matrix[0][2], matrix[1][1], matrix[2][0]])

    for a, b, c in triples:
        a, b, c = sorted([a, b, c])
        if (a == b and c < 0) or (b == c and a < 0):
            return True
    return False


pairs = [[(i, j) for j in range(3)] for i in range(3)]
pairs = pairs[0] + pairs[1] + pairs[2]

total = 0
good = 0
for p in permutations(list(range(9)), r=9):
    total += 1
    p = list(p)
    
    arr = [[-i * (j + 10) for j in range(1, 4)] for i in range(1, 4)]
    for t in range(9):
        x, y = pairs[p[t]]
        arr[x][y] = matrix[x][y]
        if is_disappointed(arr):
            break
    else:
        good += 1

print(good / total)