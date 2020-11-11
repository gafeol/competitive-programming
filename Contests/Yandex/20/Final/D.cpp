#include "bits/stdc++.h"
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define eb emplace_back
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

const int MAXN = 1000006;
const int INF = 0x3f3f3f3f;

int n, m, k;
char s[MAXN];
int ok[MAXN];

int go(int i){
    if(i > n)
        return 0;
    int &r = ok[i];
    if(r != -1)
        return r;
    if(i == n)
        return r = 1;
    if(s[i] == '0')
        return r = 0;
    if(s[i] == '1' && i+1 == n)
        return r = 0;
    r = (go(i+1) || go(i+2));
    int j = i+1;
    while(s[j] == '0' && j < n)
        j++;
    r = (r || go(j) || go(j+1));
    return r;
}

vector<deque<int>> ans;
deque<int> aux;

inline double val(deque<int> &q){
    double x = 0;
    for(int d: q){
        x *= 10;
        x += d;
    }
    return x;
}

ll pot[20];
deque<int> bsti, bstii;

inline bool merge(){
    if(ans.size() < 2)
        return 0;
    int i = ans.size()-2;    
    if(ans[i].size() > 7 || ans[i+1].size() > 7)
        return false;

    for(int a=ans[i].size()-1;a>=0;a--){
        int x = ans[i][a];
        ans[i+1].push_front(x);
    }
    ans[i].clear();
    double bst = -1;
    int sz = ans[i+1].size();

    for(int div=0;div<sz;div++){
        ans[i].push_back(ans[i+1][0]);
        ans[i+1].pop_front();
        if(div == sz-1){
            assert(ans[i+1].empty());
            if(bst < log(val(ans[i]))){
                ans.pop_back();
                return true;
            }
            break;
        }
        double tv = val(ans[i+1])*log(val(ans[i]));
        if(bst < tv){
            bst = tv;
            bsti = ans[i];
            bstii = ans[i+1];
        }
    }

    ans[i] = bsti;
    ans[i+1] = bstii;
    return false;
}

int main (){
    pot[0] = 1;
    for(int a=1;a<20;a++){
        pot[a] = 10*pot[a-1];
    }
    scanf(" %s", s);
    n = strlen(s);
    memset(ok, -1, sizeof(ok));
    go(0);
    ll val = 0;

    bool fst = true;
    int from = 0;
    for(int i=0;i<n;i++){
        if(val > 1 && go(i)){
            ans.pb(aux);
            aux.clear();
            val = 0;
            if(ans.size() - from > 20){
                if(!fst)
                    printf("**");
                fst = false;
                for(int x: ans[from]){
                    printf("%d", x);
                }
                ans[from].clear();
                from++;
            }
        }
        val *= 10;
        val += s[i] - '0';
        val = min(2ll, val);
        aux.pb(s[i]-'0');
    }
    if(!aux.empty())
        ans.pb(aux);
    while(merge());
    for(;from<(int)ans.size();from++){
        if(!fst)
            printf("**");
        fst = false;
        for(int x: ans[from])
            printf("%d", x);
         
    }
    puts("");
}

