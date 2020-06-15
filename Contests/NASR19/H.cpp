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

string alf;
string s;

vector<string> ans;

vector<string> suf;

void go(int i, string pref){
    if(i == s.size()) return ;
    ans.pb(pref + suf[i+1]); 
    for(char c : alf){
        ans.pb(pref + c + suf[i]);
        if(c != s[i])
            ans.pb(pref + c + suf[i+1]);
    }
    go(i+1, pref + s[i]);
}

int main (){
    cin >> alf;
    cin >> s;
    for(int a=0;a<s.size();a++){
        suf.pb(s.substr(a, s.size())); 
    }
    suf.pb("");
    go(0, "");
    for(char c: alf)
        ans.pb(s + c);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(string pal : ans){
        cout << pal << endl;
    }
}

