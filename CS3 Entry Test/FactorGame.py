"""n = int(input())

a = []
for i in range(n):
    num = int(input())
    a.append(num)

points = []
for i in range(n):
    count = 0
    for j in range(n):
        if a[i] % a[j] == 0:
            count += 1
    points.append(count)

for p in points:
    print(p-1)"""



