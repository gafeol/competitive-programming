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
int s[MAXN];
int d[MAXN];
vector<int> adj[MAXN];

inline void add_edge(int a, int b){
    adj[a].pb(b);
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf("%d", s+a);
	}

    stack<int> up, dw;

    for(int a=0;a<n;a++){
        auto get = [&](stack<int> &st) {
            add_edge(st.top(), a);
            st.pop();
        };
        while(!up.empty() && s[up.top()] > s[a])
            get(up);
        if(!up.empty()){
            if(s[up.top()] == s[a])
                get(up);
            else
                add_edge(up.top(), a);
        }
        up.push(a);

        while(!dw.empty() && s[dw.top()] < s[a])
            get(dw);
        if(!dw.empty()){
            if(s[dw.top()] == s[a])
                get(dw);
            else
                add_edge(dw.top(), a);
        }
        dw.push(a);

    }
    queue<int> qu;
    qu.push(0);
    memset(d, -1, sizeof(d));
    d[0] = 0;
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(int nxt: adj[u]){
            if(d[nxt] == -1){
                d[nxt] = d[u] + 1;
                qu.push(nxt);
            }
        }
    }
    printf("%d\n", d[n-1]);
}

