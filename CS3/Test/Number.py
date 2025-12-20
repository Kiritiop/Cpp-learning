n = int(input())
L = (n - 1).bit_length()
ans = n * (L + 1) - (1 << L)
print(ans)