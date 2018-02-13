inp = raw_input()
inp = inp.split()
n = int(inp[0])
k = int(inp[1])

g = []
for i in range(n):
	g.append(i+1)

resp = ""

f = [1, 1]
for i in range(n):
	f.append((i+2)*f[i+1])

for i in range(n):
	mn = 0
	mx = n-i-1
	while mx >= mn:
		m = int((mx+mn)/2)
		p = (m+1)*f[n-i-1]
		if k > p:
			mn = m+1
		else:
			mx = m-1
	resp += str(g[mn])
	resp += " "
	g.remove(g[mn])
	k -= (mn)*f[n-i-1]

print (resp)
