n = int(input())
key = input().strip()
william = input().strip()

max = 0

for skip in range(n):
    score = 0
    wi = 0
    
    for ki in range(n):
        if ki == skip:
            continue
        if wi < len(william) and william[wi] == key[ki]:
            score += 1
        wi += 1
    
    if score > max:
        max = score

print(max)