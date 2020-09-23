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

const int MAXN = 3512;

int n, m, k;
int s[MAXN];

vector<int> vals;

int main (){
    for_tests(t, tt){
        vals.clear();
        scanf("%d%d%d", &n, &m, &k);
        int sp = n - m;
        m--;
        for(int a=0;a<n;a++){
            scanf("%d", s+a);
            if(a >= sp){
                vals.pb(max(s[a-sp], s[a]));
            }
        }

        if(k >= vals.size()){
            printf("%d\n", *max_element(vals.begin(), vals.end()));
            continue;
        }

        multiset<int> q;
        int tam = vals.size() - k;
        for(int a=0;a<tam;a++)
            q.insert(vals[a]);

        int x = 0;
        for(int i=0;i<vals.size();i++){
            x = max(x, *q.begin());  
            q.erase(q.find(vals[i]));
            if(i + tam >= vals.size())
                break;
            q.insert(vals[i+tam]);
        }

        
        printf("%d\n", x);
    }
}
