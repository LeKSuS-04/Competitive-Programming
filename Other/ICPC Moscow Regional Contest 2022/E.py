''' E. Денежная система '''
# Date: 16 Oct 2022, 12Ж31Ж38
# Run time: 137 ms
# Memory: 4.24Mb
# Verdict: AC

a1, a2, a3 = map(int, input().split())

m3 = a1 + a2*2 + a3*3

s = m3 // 3
if a1 == 0 and a3 == 0:
    print(a2)
else:
    if a1 == 0:
        if a2 > 1:
            s += (m3 - 4) // 3
        if a2 > 0:
            s += (m3 - 2) // 3 + 1
    elif a1 == 1: 
        s += (m3 - 1) // 3 + 1
        if a2 > 0:
            s += (m3 - 2) // 3 + 1
    else:
        s += (m3 - 1) // 3 + 1
        s += (m3 - 2) // 3 + 1

    print(s)
