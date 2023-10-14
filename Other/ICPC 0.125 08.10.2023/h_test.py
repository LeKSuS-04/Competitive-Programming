from pwn import process


def check(location):
    init = location
    p = process("/tmp/problem")
    while True:
        d = p.recvuntil(b"\n").decode().strip()
        if d[0] == '?':
            q = int(d[2:])
            location += q
            if location < 1 or location > 54:
                print('ALERT!!')
            answer = ''
            if location % 2 == 0:
                answer += 'high'
            else:
                answer += 'low'

            if location <= 36:
                answer += ' main'
            else:
                answer += ' side'
            p.sendline(answer.encode())
        else:
            guess = int(d[2:])
            if guess == init:
                print(f"{init} correct")
            else:
                print(f"{init} incorrect: guessed {guess}")
            break


for i in range(1, 55):
    check(i)
