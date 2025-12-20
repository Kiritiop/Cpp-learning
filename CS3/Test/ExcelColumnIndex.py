s = input().strip()

ans = 0
for c in s:
    ans = ans * 26 + (ord(c) - ord('A') + 1)

print(ans)
