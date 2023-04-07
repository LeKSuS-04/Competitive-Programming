''' B. Биссектриса '''
# Date: 16 Oct 2022, 11:12:10
# Run time: 55 ms
# Memory: 4.24Mb
# Verdict: AC

a, b, c, d = (int(input()) for _ in range(4))

def check(a, b, c, d):
    return all((
        a*d == b*c,
        a + c > b + d,
        a + b + d > c,
        c + b + d > a
    ))


if any((check(a, b, c, d), check(a, b, d, c), check(a, c, b, d), check(a, c, d, b), check(a, d, b, c), check(a, d, c, b),
        check(b, a, c, d), check(b, a, d, c), check(b, c, a, d), check(b, c, d, a), check(b, d, a, c), check(b, d, c, a),
        check(c, b, a, d), check(c, b, d, a), check(c, a, b, d), check(c, a, d, b), check(c, d, b, a), check(c, d, a, b),
        check(d, b, c, a), check(d, b, a, c), check(d, c, b, a), check(d, c, a, b), check(d, a, b, c), check(d, a, c, b))):
    print(1) 
else:
    print(0)
