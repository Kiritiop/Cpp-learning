n, m = map(int, input().split())
adj = [[] for i in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)

solution = [0] * n

for i in range(n):
    used = {solution[j] for j in adj[i]}
    for g in range(1, 5):
        if g not in used:
            solution[i] = g
            break

print("".join(map(str, solution)))
