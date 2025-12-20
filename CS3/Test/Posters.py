X, Y, N = map(int, input().split())

wall = [[False] * X for i in range(Y)]

for j in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    
    for y in range(y1 - 1, y2):
        for x in range(x1 - 1, x2):
            wall[y][x] = True

count = 0
for row in wall:
    for cell in row:
        if cell:
            count += 1

print(count)
