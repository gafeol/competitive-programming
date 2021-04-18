#include "bits/stdc++.h"
using namespace std;

int main() {
    int nt;
    scanf("%d", &nt);
    for(int t=0;t<nt;t++){
        int x;
        scanf("%d", &x);
        bool ehprimo = true;
        if(x == 1) ehprimo = false;
        for(int d=2;d<x;d++){
            if(x % d == 0){
                ehprimo = false;
            }
        }
        if(ehprimo)
            printf("%d eh primo\n", x);
        else
            printf("%d nao eh primo\n", x);
    }
    return 0;
}
