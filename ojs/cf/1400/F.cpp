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

const int MAXN = 1123;
int n, m, k;

int dp[MAXN][5*MAXN];

char s[MAXN];
vector<string> xpri;

const int K = 10;

struct Vertex {
    int next[K];
    bool leaf = false;
    int cntLeaf = 0;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    //printf("add string %s v %d\n", s.c_str(), v);
    t[v].leaf = true;
    t[v].cntLeaf++;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
            t[v].cntLeaf += t[t[v].link].cntLeaf;
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

void gen(string s=""){
    int sum = 0;
    for(int a=s.size()-1;a>=0;a--){
        sum += s[a]-'0';
        if(k != sum && k%sum == 0) return;    
    }
    if(sum > k)
        return ;
    if(sum == k){
        xpri.pb(s);
        return ;
    }
    for(char d='1';d<='9';d++)
        gen(s+d);
}

const int INF = 0x3f3f3f3f;

int solve(int i, int u){
    int &r = dp[i][u];
    if(r != -1)
        return r;
    r = INF;
    get_link(u);
    //printf("i %d u %d cntLeaf %d\n", i, u, t[u].cntLeaf);
    if(t[u].cntLeaf)
        return r = INF;
    if(i == n)
        return r = 0;

    r = min(r, solve(i+1, u) + 1);
    r = min(r, solve(i+1, go(u, s[i])));
    return r;
}

int main (){
    scanf(" %s", s);
    n = strlen(s);
    scanf("%d", &k);
    gen();
    for(string x: xpri)
        add_string(x);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0));
}
