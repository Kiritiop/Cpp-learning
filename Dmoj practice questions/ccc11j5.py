N = int(input())
children = [[] for i in range(N + 1)]
    
for i in range(1, N):
    j = int(input())
    children[j].append(i)
    
f = [0] * (N + 1)
    
def dfs(u):
    ways = 1
    for v in children[u]:
        dfs(v)
        ways *= (1 + f[v])
    f[u] = ways
    
dfs(N)
print(f[N])