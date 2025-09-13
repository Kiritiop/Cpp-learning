
line1 = input().split()
n_size = int(line1[0])
m_size = int(line1[1])
    
line2 = input().split()
n = []
for x in line2:
   n.append(int(x))
    
line3 = input().split()
m = []
for x in line3:
    m.append(int(x))
    
n.sort()
m.sort()
    
i = 0
j = 0
min = float('inf')
    
while i < n_size and j < m_size:
    diff = abs(n[i] - m[j])
    if diff < min:
        min = diff
        
    if n[i] < m[j]:
        i += 1
    else:
        j += 1
            
print(min)

