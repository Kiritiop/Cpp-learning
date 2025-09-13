line = input().split()
n = int(line[0])
d = int(line[1])
k = int(line[2])

line2 = input().split()
h = []
for x in line2:
    h.append(int(x))

hits = []
for health in h:
    attacks = (health + d - 1) // d
    hits.append(attacks)

hits.sort(reverse=True)

total_regular = 0
for i in range(k, n):
    total_regular += hits[i]

print(total_regular)
