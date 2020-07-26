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

const int MAXN = 212345;

int n, m, k;

map<int, vector<pii>> ev;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int i, j;
        scanf("%d%d", &i, &j);
        if(i > j) swap(i, j);
        ev[i].pb({0, a});
        ev[j].pb({1, a});
	}

    set<int> q;
    vector<int> ans;
    for(auto it: ev){
        vector<pii> v = it.snd;
        sort(v.begin(), v.end());
        bool fim = false;
        for(pii e: v){
            int t = e.fst;
            int u = e.snd;
            //printf("at %d t %d u %d\n", it.fst, t, u);
            if(t == 1 && !q.empty() && *q.lower_bound(u) == u){
                fim = true;
            }
            if(t == 0)
                q.insert(u);
        }
        if(fim){
            //printf("fim qsz %d\n", q.size());
            q.clear();
            ans.pb(it.fst);
        }

    }
    printf("%d\n", (int)ans.size());
    for(int x: ans){
        printf("%d ", x);
    }
    puts("");
}

