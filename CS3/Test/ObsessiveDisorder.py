n = int(input())
a = list(map(int, input().split()))

mu = [1] * (n + 1)
prime = [True] * (n + 1)
primes = []

for i in range(2, n + 1):
    if prime[i]:
        primes.append(i)
        mu[i] = -1
    for p in primes:
        ip = i * p
        if ip > n:
            break
        prime[ip] = False
        if i % p == 0:
            mu[ip] = 0
            break
        else:
            mu[ip] = -mu[i]

c = [0] * (n + 1)
mu_local = mu
a_local = a
c_local = c

for j in range(1, n + 1):
    aj = a_local[j - 1]
    if aj == 0:
        continue
    for i in range(j, n + 1, j):
        c_local[i] += mu_local[i // j] * aj

ans = 0
for i in range(2, n + 1):
    x = c_local[i]
    ans += x if x >= 0 else -x

print(ans)
