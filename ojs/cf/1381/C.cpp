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
int s[MAXN];
vector<int> pos[MAXN];
int cnt[MAXN];
int ans[MAXN];
set<pii> q;
vector<int> freepos;
vector<int> vals;
int main (){
    for_tests(t,tt){
        q.clear();
        int x, y;
        scanf("%d%d%d", &n, &x, &y);
        for(int a=0;a<=n+1;a++){
            pos[a].clear();
            cnt[a] = 0;
        }
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            cnt[s[a]]++;
            pos[s[a]].pb(a);
        }

        int neutral = 1;
        while(cnt[neutral])
            neutral++;

        for(int a=0;a<=n+1;a++){
            if(cnt[a] > 0)
                q.insert({-cnt[a], a});
        }
        while(x--){
            y--;
            pii p = *q.begin();
            q.erase(q.begin());
            ans[pos[p.snd].back()] = p.snd;
            pos[p.snd].pop_back();
            p.fst++;
            if(p.fst < 0)
                q.insert(p);
        }
        pii big = make_pair(-1, -1);
        if(!q.empty()){
            big = *q.begin();
            q.erase(q.begin());
        }
        freepos.clear();
        vals.clear();
        for(int po: pos[big.snd])
            freepos.pb(po);
        while(!q.empty()){
            pii p = *q.begin();
            q.erase(q.begin());
            int val = p.snd;
            for(int po: pos[val])
                freepos.pb(po);
            int qtd = -p.fst;
            while(qtd && y){
                vals.pb(val);
                qtd--;
                y--;
            }
        }
        while(y--){
            assert(big.fst < 0);
            assert(big.snd != -1);
            big.fst++;
            vals.pb(big.snd);
        }
        /*
        puts("vals:");
        for(int a=0;a<vals.size();a++)
            printf("%d%c", vals[a], " \n"[a==sz-1]);
        puts("freepos:");
        for(int a=0;a<sz;a++)
            printf("%d%c", freepos[a], " \n"[a==sz-1]);
            */
        int deg = 0;
        for(int a=0;a<freepos.size();a++){
            if(deg < vals.size() && vals[deg] != s[freepos[a]])
                ans[freepos[a]] = vals[deg++];
            else
                ans[freepos[a]] = neutral;
        }
        if(deg == vals.size()){
            puts("YES");
            for(int a=0;a<n;a++){
                printf("%d ", ans[a]);
            }
            puts("");
        }
        else
            puts("NO");
    }
}

