f = [0, 1, 1]

for i in range(1000):
	f.append(f[i+3-1]+f[i+3-3])

j = int(raw_input())
print(f[j])
