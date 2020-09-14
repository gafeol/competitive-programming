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
char s[MAXN];
char val[MAXN];
int sz[MAXN], p[MAXN];

int raiz(int u){
    if(p[u] == u) return u;
    return p[u] = raiz(p[u]);
}

void join(int i, int j){
    i = raiz(i);
    j = raiz(j);
    if(i == j) return;
    if(sz[i] < sz[j]) swap(i, j);
    p[j] = i;
    sz[i] += sz[j];
}

int main (){
    for_tests(t, tt){
        scanf("%d%d", &n, &k);
        scanf(" %s", s);
        for(int a=0;a<n;a++){
            sz[a] =1;
            p[a] = a;
            val[a] = '?';
        }
        for(int a=k;a<n;a++){
            join(a-k, a);
        }
        bool ok = true;
        for(int a=0;a<n;a++){
            raiz(a);
            if(s[a] != '?'){
                if(val[p[a]] == '?' || val[p[a]] == s[a])
                    val[p[a]] = s[a];
                else
                    ok = false;
            }
        }
        for(int a=0;a<n;a++){
            s[a] = val[p[a]];
        }
        int cnt[2];
        cnt[0] = cnt[1] = 0;
        queue<int> var;
        for(int a=0;a<k;a++){
            if(s[a] == '?')
                var.push(a);
            else
                cnt[s[a]-'0']++;
        }
        while(!var.empty()){
            int i = var.front();
            var.pop();
            if(cnt[0] <= cnt[1]){
                val[p[i]] = '0';
                cnt[0]++;
            }
            else{
                val[p[i]] = '1';
                cnt[1]++;
            }
        }
        if(cnt[0] != cnt[1])
            ok = false;
        if(!ok){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
}
