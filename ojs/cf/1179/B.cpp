#include "bits/stdc++.h"
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

const int MAXN = 212345;

int n, m, k;

map<pii, bool> seen;

int main (){
	scanf("%d%d", &n, &m);
    int i = 1, j = 1;
    int ii = n, jj = m;
    int t = 0;
    pii lst = {-1, -1};
    while(i < ii || (i == ii && j <= jj)){
        if(!t){
            if(lst.fst != -1){
                assert(seen[make_pair(i - lst.fst, j - lst.snd)] == false);
                seen[make_pair(i - lst.fst, j - lst.snd)] = true;
            }
            printf("%d %d\n", i, j);
            lst = {i, j};
            if(j < m)
                j++;
            else{
                j = 1;
                i++;
            }
        }
        else{
            printf("%d %d\n", ii, jj);
            if(lst.fst != -1){
                assert(seen[make_pair(ii - lst.fst, jj - lst.snd)] == false);
                seen[make_pair(ii - lst.fst, jj - lst.snd)] = true;
            }
            lst = {ii, jj};
            if(jj == 1){
                jj = m;
                ii--;
            }
            else
                jj--;
        }
        t ^= 1;
    }
}

