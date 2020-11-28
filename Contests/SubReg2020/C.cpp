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

typedef tuple<ull, ull> H;

const int MAXN = 1123456;

int n[2];

vector<string> s[2];
vector<vector<H>> ph[2];
char pal[MAXN];

tuple<ull, ull> pri = {47, 327};

H add(H a, H b){
    auto [i, j] = a;
    auto [k, l] = b;
    return {i + k, j + l};
}
H mult(H a, H b){
    auto [i, j] = a;
    auto [k, l] = b;
    return {i * k, j * l};
}


H expo(H base, ll e){
    if(e == 0)
        return {1, 1};
    H ans = expo(base, e/2);
    ans = mult(ans, ans);
    if(e&1)
        ans = mult(ans, base);
    return ans;
}

tuple<ull, ull> h(string &st){
    tuple<ull, ull> hx = {0, 0};
    for(char c: st){
        H val = {c-'a', c-'a'};
        hx = mult(hx,pri);
        hx = add(hx,val);
    }
    return hx;
}

int solve(){
    map<H, bool> mrk;
    map<H, bool> seen[2];

    ph[0].clear(); ph[1].clear();

    for(int t=0;t<2;t++){
        for(int i=0;i<n[t];i++){
            string &st = s[t][i];
            H ini = {0, 0};
            vector<H> aux;
            for(char c: st){
                ini = mult(ini, pri);
                H val = {c-'a', c-'a'};
                ini = add(ini, val);
                aux.pb(ini);
            }
            ph[t].pb(aux);
        }
    }

    for(int t=0;t<2;t++){
        for(string &st : s[t])
            seen[t][h(st)] = 1;
    }

    map<H, bool> dead;
    map<int, bool> deadId;


    for(int si=0;si<n[1];si++){
        string &st = s[1][si];
        H suf = {0, 0};
        for(int i=st.size()-1;i>0;i--){
            int tam = st.size()-1 - i + 1;
            H val = {st[i]-'a', st[i]-'a'};
            suf = add(suf, mult(expo(pri, tam), val));
            if(seen[1].find(ph[1][si][i]) != seen[1].end()){
                mrk[suf] = 1;
            }
        }
    }
    for(int si=0;si<n[0];si++){
        string &st = s[0][si];
        H suf = {0, 0};
        for(int i=st.size()-1;i>0;i--){
            int tam = st.size()-1 - i + 1;
            H val = {st[i]-'a', st[i]-'a'};
            suf = add(suf, mult(expo(pri, tam), val));
            if(seen[0].find(ph[0][si][i]) != seen[0].end() && mrk.find(suf) != mrk.end()){
                deadId[i] = true;
                dead[ph[0][si][i]] = true;
            }
        }
    }

    int ans = n[0];
    for(int a=0;a<n[0];a++){
        if(deadId[a] || dead[h(s[0][a])])
            ans--;

    }
    return ans;
}

int main (){
	scanf("%d%d", &n[0], &n[1]);
    for(int t=0;t<2;t++){
        for(int a=0;a<n[t];a++){
            scanf(" %s", pal);
            string st = pal;
            if(t == 1)
                reverse(st.begin(), st.end());    
            s[t].pb(st);
        }
    }

    printf("%d ", solve());
    swap(s[0], s[1]);
    swap(n[0], n[1]);
    printf("%d\n", solve());
    return 0;
}

