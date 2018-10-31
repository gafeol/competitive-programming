n, s = raw_input().split()
n = int(n)
s = int(s)
v = []
for i in range(n):
	name, ss = raw_input().split()
	ss = int(ss)
	v.append((ss, name))
v.sort()
i = len(v)
resp = [];
while i > 0:
	i -= 1;
	if (s >= v[i][0]):
		s -= v[i][0]
		resp.append(v[i][1])

if(s == 0):
	print(len(resp))
	for i in resp:
		print(i)
else:
	print(0)
