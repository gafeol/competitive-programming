i = int(raw_input())
n = i

def gcd(a, b):
	if (b == 0):
		return a
	return gcd(b, a%b)

lcm = 1

for i in range(n):
	j = i+1
	lcm = (lcm*j)/gcd(lcm, j)

print(lcm)
