def aba(c):
    if c == 'A':
        return "A"
    prv = ord(c) - 1
    h = aba(chr(prv))
    return h + c + h


c = SS';
res = aba(c)
print(len(res));
