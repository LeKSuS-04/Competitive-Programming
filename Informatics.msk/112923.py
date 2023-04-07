''' Problem No. 112923 '''
# https://informatics.msk.ru/mod/statements/view.php?chapterid=112923#1
# Date: 2022-3-23 11:32:40
# Max proccessor time: 0.063
# Max memory usage: 4067328
# Verdict: AC

TC = int(input())

for _ in range(TC):
    _ = input()
    seq = list(map(int, input().split()))
    sorted_seq = sorted(seq)

    if seq != sorted_seq and seq != sorted_seq[::-1]:
        print(*seq)
    else:
        print(seq[1], seq[0], *seq[2:])
