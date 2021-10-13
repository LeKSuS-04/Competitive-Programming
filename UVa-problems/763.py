''' UVa 763 - Fibinary Numbers '''
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=704
# Date: 2021-09-14 19:29:36
# Runtime: 0.110
# Verdict: AC

from sys import stdin

MAX = 105
fib = []

def create_fibs():
    global fib
    fib = [1, 2]
    while len(fib) < MAX:
        fib.append(fib[-1] + fib[-2])

def fibs_to_int(f):
    val = 0
    for i, b in enumerate(f[::-1]):
        if b == '1':
            val += fib[i]
    return val

def int_to_fibs(x):
    out = ['0'] * MAX
    for i in range(MAX - 1, -1, -1):
        if fib[i] <= x:
            out[i] = '1'
            x -= fib[i]

    while len(out) > 1 and out[-1] == '0':
        out.pop()

    return ''.join(out[::-1])


if __name__ == '__main__':
    create_fibs()

    lines = []
    case_n = 0
    for line in stdin:
        line = line.strip()
        if line != "":
            lines.append(line)

        if len(lines) == 2:
            x, y = lines
            lines.clear()

            x_val, y_val = fibs_to_int(x), fibs_to_int(y)

            val = x_val + y_val
            f = int_to_fibs(val)

            if (case_n != 0):
                print()
            print(f)
            case_n += 1
