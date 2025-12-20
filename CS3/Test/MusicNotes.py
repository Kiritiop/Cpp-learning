N, Q = map(int, input().split())

a = []
for i in range(N):
    a.append(int(input()))

queries = []
for j in range(Q):
    queries.append(int(input()))

prefix = []
total = 0
for x in a:
    total += x
    prefix.append(total)

for t in queries:
    for i in range(N):
        if t < prefix[i]:
            print(i + 1)
            break
