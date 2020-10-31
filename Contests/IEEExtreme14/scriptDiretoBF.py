import os

os.system("rm out");

sp  = ["'", '"']

def add(c):
    if c == r"'":
        return "\'"
    elif c == '"':
        return '\"'
    else:
        return c


for c1 in range(33, 127):
    for c2 in range(33, 127):
        for c3 in range(33, 127):
            fin = open("in", "w")
            fout = open("out", "a")
            s = ""
            s = s + add(chr(c1))
            s = s + add(chr(c2))
            s = s + add(chr(c3))
            print("Checking " + repr(s))
            fout.write("\n" + s + " ")
            fout.close()
            fin.write(s)
            fin.close()
            os.system("bf code.bf < in >> out")
