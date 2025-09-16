t, n = map(int, input().split())

for i in range(t):
    s = input()
    counts = {}
    for char in s:
        counts[char] = counts.get(char, 0) + 1

    is_heavy = [counts[char] > 1 for char in s]

    alternate = True
    if n > 1:
        for i in range(n - 1):
            if is_heavy[i] == is_heavy[i+1]:
                alternate = False
                break
    
    if alternate:
        print("T")
    else:
        print("F")