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

const int MAXN = 212345;

int n, m, k;

int main (){
    IOS();
    int t;
    cin >> t;
    while(t--){
        string s, ss;
        cin >> s;
        cin >> ss;
        map<char, int> cnt;
        vector<char> st;
        for(char c: ss)
            cnt[c]++;
        for(char c: s){
            if(cnt[c])
                cnt[c]--;
            else
                st.pb(c);
        }
        sort(st.begin(), st.end());
        bool p1 = false, p2 = false;
        string res1 = "", res2 = "";
        for(char c: st){
            if(!p1 && c >= ss[0]){
                res1 += ss;
                p1 = true;
            }
            if(!p2 && c > ss[0]){
                res2 += ss;
                p2 = true;
            }
            res1.pb(c);
            res2.pb(c);
        }
        if(!p1)
            res1 += ss;
        if(!p2)
            res2 += ss;
        cout << min(res1, res2) << endl;
    }

}

