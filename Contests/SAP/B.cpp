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

map<string, string> adj;

string go(string s){
    int i = 0, sz = 1;
    string ans = "";
    while(i < s.size()){
        while(i + sz < s.size() && s[i+sz] == s[i])
            sz++;
        ans += adj[s.substr(i, sz)];
        i += sz;
        sz = 1;
    }
    return ans;
}

int main (){
	scanf("%d%d", &n, &m);
    for(int a=0;a<m;a++){
        string s1, s2;
        cin >> s1 >> s2;
        adj[s1] = s2;
    }

    string s = "A";
    while(n--){
        s = go(s);
    }
    int na = 0;
    for(char x: s){
        na += (x == 'A');
    }
    printf("%d %d\n", na, (int)s.size()-na);
}

