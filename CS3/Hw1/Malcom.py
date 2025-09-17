n, k = map(int, input().split())
lengths = [len(input().strip()) for i in range(n)]

count = 0
freq = [0] * 21
left = 0

for right in range(n):
    count += freq[lengths[right]]
    freq[lengths[right]] += 1
    if right - left >= k:
        freq[lengths[left]] -= 1
        left += 1

print(count)
