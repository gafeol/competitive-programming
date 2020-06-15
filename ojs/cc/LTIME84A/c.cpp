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

int n, m, k;
char s[MAXN];
char ss[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        scanf(" %s", s);
        scanf(" %s", ss);
        map<char, int> has;
        for(int a=0;a<n;a++){
            has[s[a]] = a;
        }
        bool ok = true;
        for(int a=0;a<n;a++){
            if(s[a] < ss[a])
                ok = false;
            if(has.find(ss[a]) == has.end())
                ok = false;
        }
        if(!ok){
            puts("-1");
            continue;
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(s[i] != ss[i]){
                vector<int> passo;
                for(int j=0;j<n;j++)
                    if(ss[j] == ss[i] && ss[j] != s[j]){
                        s[j] = ss[i];
                        passo.pb(j); 
                    }
                if(passo.empty()) 
                    continue;
                passo.pb(has[ss[i]]);
                sort(passo.begin(), passo.end());
                passo.erase(unique(passo.begin(), passo.end()), passo.end());
                ans.pb(passo);
            }
        }
        printf("%d\n", (int)ans.size());
        for(vector<int> &v: ans){
            printf("%d ", (int)v.size());
            for(int x: v){
                printf("%d ", x); 
            }
            puts("");
        }
    }
}


