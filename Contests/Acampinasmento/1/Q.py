inp = raw_input()
resp = 0

g = [0]*26
f = [1, 1]
for i in range(35):
	f.append((i+2)*f[i+1])

for i in inp:
	g[ord(i)-97] += 1

def comb(g):
	div = 1
	sm = 0
	for i in range(26):
		div *= f[g[i]]
		sm += g[i]
	return f[sm]/div

def calc(inp, t, p):
	resp = 0
	if (p == len(inp)):
		return 1
	for i in range(26):
		if ord(inp[p])-97 == i:
			t[i] -= 1
			resp += calc(inp, t, p+1)
			return resp
		elif t[i] > 0:
			t[i]-=1
			resp += comb(t)
			t[i]+=1
	return resp

print( calc(inp, g, 0) )
