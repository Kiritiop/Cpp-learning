n = int(input().strip())
b = list(map(int, input().split()))

a = [0] * n
a[0] = b[0]

for i in range(1, n - 1):
    if b[i] <= b[i - 1]:
        a[i] = b[i]
    else:
        a[i] = min(b[i], b[i - 1])

a[n - 1] = b[n - 2]

result = 0
for i in range(n - 1):
    if b[i] < max(a[i], a[i + 1]):
        a[i] = b[i]
        a[i + 1] = b[i]
    result += a[i]
result += a[n - 1]

print(result)