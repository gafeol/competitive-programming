import sys

n, ho = list(map(int, input().split()))
a = list(map(int, input().split()))
s = sum(a)

acm = 0
pico = 0
for x in a:
    acm += x
    pico = max(pico, acm)

lo = 0
hi = 10**100
ans = -1

while lo <= hi:
    mid = (lo + hi) // 2
    my = pico + s * mid
    ex = ho - (mid * n) * (mid * n + 1) // 2
    if my >= ex:
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1

assert ans != -1

my = s * ans
ex = ho - (ans * n) * (ans * n + 1) // 2
for i in range(-1, n):
    my += a[i]
    ex -= (1 + i + ans * n)
    if my >= ex:
        print(1 + i + ans * n)
        sys.exit(0)

assert False
