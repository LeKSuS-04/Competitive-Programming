from fractions import Fraction

p, q = map(int, input().split())
x, y = map(int, input().split())
x, y = min(x, y), max(x, y)

goal = Fraction(p, q)


def angle(a: Fraction, b: Fraction) -> Fraction:
    return abs(a - b) % 360


vs = Fraction(6)
vm = vs / 60
vh = vm / 12

answers = []
v1, v2 = Fraction(0), Fraction(0)
if (x, y) == (1, 2):
    v1, v2 = vs, vm
elif (x, y) == (2, 3):
    v1, v2 = vm, vh
elif (x, y) == (1, 3):
    v1, v2 = vs, vh

t = goal / (v1 - v2)
T = 360 / (v1  - v2)
while t <= 12 * 60 * 60:
    if t > 0:
        answers.append(t)
    t += T

t = goal / (v2 - v1)
while t <= 12 * 60 * 60:
    if t > 0:
        answers.append(t)
    t += T

answers = sorted(list(set(answers)))
print(len(answers))
for a in answers:
    print(a.numerator, a.denominator)
