#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212;

int n, m, k;
int x;
char ss[MAXN];
int s[MAXN], res[MAXN];

bool testa(int i){
    //debug("testa %d com %d\n", i, res[i]);
    for(int som = n-1;som>=0;som--){
        int val = 0;
        for(int a=0;a<x;a++){
            int b = som - a;
            if(b < 0 || b >= x) continue;
            if(min(a, b) < i) return true;
            //printf("val += res[%d] %d * res[%d] %d\n", a, res[a], b, res[b]);
            val = (val + res[a]*res[b])%10;
        }
        //printf("val %d == s[%d] %d\n", val, som, s[som]);
        if(val != s[som]) return false;
    }
    //debug("deu true\n");
    return true;
}

bool go(int i){
    //printf("go %d\n", i);
    if(i < 0)
        return true;
    for(int d=0;d<=9;d++){
        res[i] = d;
        if(testa(i) && go(i-1))
            return true;
    }
    return false;
}


int main (){
    scanf(" %s", ss);
    n = strlen(ss);
    for(int a=0;a<n;a++){
        s[n-1-a] = ss[a]-'0';
    }
    if(n%2 == 0){
        puts("-1");
        return 0;
    }
    x = (n+1)/2;
    if(go(x-1)){
        for(int a=x-1;a>=0;a--){
            printf("%d", res[a]); 
        }
        puts("");
    }
    else{
        puts("-1");
        return 0;
    }

}

