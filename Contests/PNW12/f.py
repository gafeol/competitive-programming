def f(x):
	if(x == 0):
		return 1
	return f(x-1)*x

print f(16)
print f(6)

print (f(16)/(f(6) * f(10)))
