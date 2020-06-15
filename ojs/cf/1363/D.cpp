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

int ans[MAXN];
vector<vector<int>> S;

void print(){
    printf("!");
    for(int a=0;a<k;a++)
        printf(" %d", ans[a]);
    puts("");
    fflush(stdout);

    char ver[20];
    scanf(" %s", ver);
    if(ver[0] == 'I')
        exit(0);
}

int qry(int i, int j){
    map<int, bool> mrk;
    vector<int> x;
    for(int a=i;a<=j;a++){
        for(int v: S[a]){
            mrk[v] = 1;
        }
    }
    for(int a=1;a<=n;a++){
        if(mrk.find(a) == mrk.end())
            x.pb(a);
    }
    printf("? %d", (int)x.size());
    for(int v: x){
        printf(" %d", v);
    }
    puts("");
    fflush(stdout);

    int ans;
    scanf("%d", &ans);
    if(ans == -1)
        exit(0);
    return ans;
}

int qry2(int i){
    map<int, bool> mrk;
    vector<int> x;
    for(int v: S[i]){
        mrk[v] = 1;
    }
    for(int a=1;a<=n;a++){
        if(mrk.find(a) == mrk.end())
            x.pb(a);
    }
    printf("? %d", (int)x.size());
    for(int v: x){
        printf(" %d", v);
    }
    puts("");
    fflush(stdout);

    int ans;
    scanf("%d", &ans);
    if(ans == -1)
        exit(0);
    return ans;
}

void put(int i, int j, int val){
    for(int a=i;a<=j;a++)
        ans[a] = val;
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        S.clear();
        for(int a=0;a<k;a++){
            int x;
            scanf("%d", &x);

            vector<int> c;
            while(x--){
                int y;
                scanf("%d", &y);
                c.pb(y);
            }
            S.pb(c);
        }
        int i = 0, j = S.size()-1;
        int mx = qry(0, -1);
        if(i == j){
            ans[i] = mx;
        }
        int o = 0;
        while(i < j){
            int m = (i + j)/2; 
            int q = qry(i, m);
            if(q == mx){
                put(i, m, mx);
                i = m+1;
            }
            else{
                put(m+1, j, mx); 
                j = m;
            }
        }
        ans[i] = qry2(i);
        print();
    }
}

