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

const int MAXN = 312345;

int n, m, k;

int to[MAXN];
int q[MAXN];

int dp[MAXN][2];

int S;

int getind(int x){
    if(x < n - S)
        return x + S+1;
    else
        return x - (n-S)+1;
}
vector<int> adj[MAXN];

int go(int i, int usd){
    if(i == n) return 0;
    int &r = dp[i][usd];    
    if(r != -1) return r;
    r = go(to[i]+1, usd) + 1;
    if(!usd){
        if(adj[i].size() > 0)
            r = max(r, go(to[i]+1, 1) + (int)adj[adj[i][0]].size() + 2);
        r = max(r, (int)adj[i].size() + (i == 0 && to[i] == n-1));
    }
    return r;
}
void re(int i, int usd){
    //printf("Re %d %d\n", i, usd);
    if(i == n) {
        //printf("1 1\n");
        return ;
    }
    int r = go(i, usd);    
    //printf("Valor r %d\n",r);
    if(r == go(to[i]+1, usd)+1){
        //puts("entra aqiu");
        return re(to[i]+1, usd);
    }
    if(!usd){
        if(adj[i].size() > 0 && r == go(to[i]+1, 1) + (int)adj[adj[i][0]].size() + 2){
            int u = adj[i][0];
            //puts("entra aqiu 2");
            printf("%d %d\n", getind(u), getind(to[u]));
            return ;
        }
        printf("%d %d\n", getind(i), getind(to[i]));
        return ;
    }
}


int main (){
	scanf("%d", &n);
    int cnt = 0;  
    int from = 0;
    vector<char> inp(n);
	for(int a=0;a<n;a++){
        scanf(" %c", &inp[a]);
        cnt += (inp[a] == '(' ? 1 : -1);
        if(cnt < 0){
            from = a+1;
            cnt = 0;
        }
	}
    vector<char> s;
    S = from;
    int ate = from;
    for(;from < n;from++)
        s.pb(inp[from]);
    for(int i=0;i<ate;i++)
        s.pb(inp[i]);
    cnt = 0;
    for(int a=0;a<n;a++){
        cnt += (s[a] == '(' ? 1 : -1);
        if(cnt < 0){
            puts("0\n1 1");
            return 0;
        }
    }
    if(cnt > 0){
        puts("0\n1 1");
        return 0;
    }
    cnt = 0;
    map<int, int> freq;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        cnt += (c == '(' ? 1 : -1);
        if(c == ')'){
            to[freq[cnt+1]] = i;
        }
        else{
            if(cnt > 1)
                adj[freq[cnt-1]].pb(i);
            freq[cnt] = i;
        }
    }

    for(int i=0;i<n;i++){
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) { return adj[a].size() > adj[b].size();});
    }
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0);
    printf("%d\n", ans);
    re(0,0);
}
