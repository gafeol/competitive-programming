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

unordered_map<string, int> id;

vector<string> names;

vector<int> adj[MAXN];
int cnt;
int st;

void add(string s){
    if(id.find(s) == id.end()){
        id[s] = cnt++;
        names.pb(s);
        if(s == "Isenbaev")
            st = cnt-1;
    }
}

int d[MAXN];

void go(int u){
    queue<int> q;
    q.push(u);
    d[u] = 0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int nxt: adj[u]){
            if(d[nxt] != -1) continue;
            d[nxt] = d[u] + 1;
            q.push(nxt);
        }
    }
}

void link(string a, string b){
    adj[id[a]].pb(id[b]);
    adj[id[b]].pb(id[a]);
}

int main (){
    memset(d, -1, sizeof(d));
    st=-1;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        vector<string> nm;
        for(int i=0;i<3;i++){
            scanf(" %s", s);
            nm.pb(s);
            add(s);
            for(int j=i-1;j>=0;j--){
                link(nm[i], nm[j]);
            }
        }
	}
    sort(names.begin(), names.end());
    if(st != -1)
        go(st);
    for(string s: names){
        cout << s << " "; 
        if(d[id[s]] == -1)
            cout << "undefined" << endl;
        else
            cout << d[id[s]] << endl;
    
}

