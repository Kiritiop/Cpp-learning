n = int(input())
a = list(map(int, input().split()))
a = [0] + a

mu = [1] * (n + 1)
prime = [True] * (n + 1)
primes = []
for i in range(2, n + 1):
    if prime[i]:
        primes.append(i)
        mu[i] = -1
    for p in primes:
        if i * p > n:
            break
        prime[i * p] = False
        if i % p == 0:
            mu[i * p] = 0
            break
        else:
            mu[i * p] = -mu[i]

c = [0] * (n + 1)
for j in range(1, n + 1):
    for i in range(j, n + 1, j):
        c[i] -= mu[i // j] * a[j]

ans = 0
for i in range(2, n + 1):
    ans += abs(c[i])

print(ans)