S = input().strip()
c = int(input())

pairs = []
i = 0
while i < len(S):
    char = S[i]
    i += 1
    num_start = i
    while i < len(S) and S[i].isdigit():
        i += 1
    count = int(S[num_start:i])
    pairs.append((char, count))

total_len = sum(count for i, count in pairs)
pos = c % total_len

for ch, cnt in pairs:
    if pos < cnt:
        print(ch)
        break
    pos -= cnt