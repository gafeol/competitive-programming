import os
import random
import sys

random.seed()

t = sys.argv[1]
os.system("make E")

for tt in range(0, t):
	os.system("./E")
	m = random.randint(1, 10001);
	os.system(m);
	n = random.randint(1, 10);
	os.system(n);
	for i in range(0, n):
		os.system(random.randint(1, 10));
