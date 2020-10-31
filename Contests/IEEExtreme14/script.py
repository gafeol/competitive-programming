import os

for c1 in range(33, 127):
    for c2 in range(33, 127):
        for c3 in range(33, 127):
            print("Checking " + chr(c1) + chr(c2) + chr(c3))
            os.system("echo \"" + chr(c1) + chr(c2) + chr(c3) + "\" >> out");
            os.system("echo \" \" >> out");
            os.system("echo \"" + chr(c1) + chr(c2) + chr(c3) + "\" > in");
            os.system("python3 interpretador.py code.bf < in >> out")
            os.system("echo \"\n\" >> out");
