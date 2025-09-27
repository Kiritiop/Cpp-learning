n = int(input())
data = []
for i in range(n):
    data.append(input().strip())

max = 0
left = [0] * n
right = [0] * n

count = 0
for i in range(n):
    if data[i] == 'S':
        count += 1
    else:
        count = 0
    left[i] = count

count = 0
for i in range(n-1, -1, -1):
    if data[i] == 'S':
        count += 1
    else:
        count = 0
    right[i] = count

for i in range(n):
    if data[i] == 'P':
        total = 0
        if i > 0:
            total += left[i-1]
        if i < n-1:
            total += right[i+1]
        total += 1
        if total > max:
            max = total
    else:
        if left[i] > max:
            max = left[i]

if max > n:
    max = n

print(max)