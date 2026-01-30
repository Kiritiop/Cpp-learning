G = int(input())
P = int(input())
planes = [int(input()) for i in range(P)]
    
parent = list(range(G + 1))  
    
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]
    
def union(x, y):
    parent[find(x)] = find(y)
    
count = 0
for g in planes:
    available = find(g)
    if available == 0:
        break
    union(available, available - 1)
    count += 1
    
print(count)

