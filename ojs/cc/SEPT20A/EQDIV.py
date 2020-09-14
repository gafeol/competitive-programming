import copy
k = int(input())
t = int(input())
for tt in range(1, t+1):
    n = int(input())
    S = 0 
    ans = [0]*(n+1)
    for i in range(1, n+1):
        S = S + i**k 
    oriS = copy.copy(S)
    mnDif = copy.copy(S)
    o = 0
    dif = [0]*(n+1)
    for i in range(n, 0, -1):
        Sm = S - i**k
        oo = o + i**k
        dif[i] = abs(Sm - oo);
        if(mnDif > dif[i]):
            mnDif = dif[i];
        if(oo < Sm):
            o = oo
            S = Sm
    mnDif = min(mnDif, abs(S - o))
    S = oriS
    o = 0;
    if mnDif != S:
        for i in range(n, 0, -1):
            Sm = S - i**k
            oo = o + i**k
            if(mnDif == dif[i]):
                ans[i] = 1;
                break;
            if(oo < Sm):
                o = oo
                S = Sm
                ans[i] = 1;
    print(mnDif)
    for i in range(1, n+1):
        print(ans[i], end="")
    print()
