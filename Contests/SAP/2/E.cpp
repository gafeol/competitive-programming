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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345, MAX = 10000000;

int n;
ull E[MAXN], K[MAXN];
ull A, B, C, S;

inline ull xorshift(ull x){
    x^=(x<<A);
    x^=(x>>B);
    x^=(x<<C);
    return x;
}

unordered_map<ull, int> pos;
vector<ull> path;
vector<int> cyc;

int cycsz, icyc;

inline ull get(ull i){
    if(i < path.size())
        return path[i];
    if(cycsz == -1) 
        return 0;
    i -= icyc;
    i %= cycsz;
    return path[icyc + i];
}


int main (){
	scanf("%d%llu%llu%llu%llu", &n, &S, &A, &B, &C);
    while(path.size() < MAX && pos.find(S) == pos.end()){
        //printf("path sz %d S %llu\n", (int)path.size(), S);
        pos[S] = path.size();
        path.pb(S);
        S = xorshift(S);
    }
    cycsz = -1;
    if(pos.find(S) != pos.end()){
        cycsz = path.size() - pos[S];
        icyc = pos[S];
    }
	for(int a=0;a<n;a++)
        scanf("%llu", E+a);
    for(int a=0;a<n;a++)
        scanf("%llu", K+a);
    for(int a=0;a<n;a++){
        ull x = (E[a]^get(K[a]));
        printf("%llu%c", x, " \n"[a==n-1]);
    }
}

