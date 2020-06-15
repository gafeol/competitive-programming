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

const int MAXN = 212345;
typedef unsigned long long uint64;

int n, m, k;
uint64 s[4];

unordered_map<uint64, pii> has;
unordered_map<uint64, int> mrk[4];

uint64 state[2];
uint64 xoroshiro128plus(uint64 s[2]) {
    uint64 s0 = s[0];
    uint64 s1 = s[1];
    //printf("s0 %llu s1 %llu\n", s0, s1);
    uint64 result = s0 + s1;
    //printf("result %llu\n", result);
    s1 ^= s0;
    s[0] = (((s0 << (uint64)55) | (s0 >> (uint64)9)) ^ s1 ^ (s1 << (uint64)14));
    s[1] = ((s1 << (uint64)36) | (s1 >> (uint64)28));
    return result;
}


unsigned long long int X = 0x7263d9bd8409f526ULL;
const int st = 6000;
void go(int t){
    state[0] = s[t]; state[1] = (s[t] ^ X);
    //printf("bef %llu %llu\n", state[0], state[1]);
    int cnt = 1;
    while(cnt < st){
        uint64 x = xoroshiro128plus(state);
        x &= (1ull<<((uint64)n))-1ull;
        mrk[t][x] = cnt;
        cnt++;
    }
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<4;a++)
        scanf("%llu", s+a);
    for(int t=0;t<4;t++)
        go(t);
    for(auto it: mrk[0]){
        for(auto it2: mrk[1]){
            has[it.fst^it2.fst] = {it.snd, it2.snd}; 
        }
    }
    for(auto it: mrk[2]){
        for(auto it2: mrk[3]){
            ll xo = it.fst ^ it2.fst;
            if(has.find(xo) != has.end()){
                printf("%d %d %d %d\n", has[xo].fst, has[xo].snd, it.snd, it2.snd); 
                return 0;
            }
        }
    }
    assert(false);
}

