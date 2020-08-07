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
char s[MAXN], ss[MAXN];
vector<int> quer[300];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", s);
        scanf(" %s", ss);
        bool ok = true;
        for(int a='a';a<='z';a++){
            quer[a].clear();
        }
        vector<int> has;
        for(int a=0;a<n;a++){
            has.pb(s[a]);
            has.pb(ss[a]);
            if(ss[a] < s[a]){
                ok = false;
                break;
            }
            quer[s[a]].pb(ss[a]);
        }
        if(!ok){
            puts("-1");
            continue;
        }
        sort(has.begin(), has.end());
        has.erase(unique(has.begin(), has.end()), has.end());
        set<int> carry;
        int ans = 0;
        for(int x: has){
            if(quer[x].empty() && carry.find(x) == carry.end()) continue;
            for(int y: quer[x])
                carry.insert(y);   
            carry.erase(x);
            if(!carry.empty()){
                ans++;
                int mn = *carry.begin();
                for(auto x: carry){
                    quer[mn].pb(x);
                }
                carry.clear();
            }
        }
        printf("%d\n", ans);
    }
}
