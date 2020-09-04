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

class TapeMeasure {
    public: 
        vector<string> draw(int, int);
};


vector<string> TapeMeasure::draw(int l, int r){
    vector<string> res;
    string ans;
    ans.clear();
    ans.resize((r - l)*2 + 1, '#');
    res.pb(ans);
    ans = "";
    for(int a=l;a<=r;a++){
        ans.pb('#');
        if(a < r)
            ans.pb(' ');
    }
    res.pb(ans);
    ans = "";
    for(int a=l;a<=r;a++){
        if(a%5 == 0)
            ans.pb('#');
        else
            ans.pb(' ');
        if(a < r)
            ans.pb(' ');
    }
    res.pb(ans);
    ans = "";
    for(int a=l;a<=r;a++){
        if(a%10 == 0)
            ans.pb('#');
        else
            ans.pb(' ');
        if(a < r)
            ans.pb(' ');
    }
    res.pb(ans);
    ans.clear();
    ans.resize(2*(r-l)+5, ' ');
    if((l-1)%10 == 0){
        string num = to_string(l-1);
        if(num.size() == 3)
            ans[0] = num[2];
        assert(num.size() <= 3);
    }
    int pos = 0;
    for(int a=l;a<=r;a++){
        if(a%10 == 0){
            string num = to_string(a);
            for(int i=0;i<num.size();i++){
                ans[pos+i] = num[i];
            }
        }
        pos += 2;
    }
    ans.resize(2*(r-l)+1);
    res.pb(ans);
    return res;
}
/*
int main (){
    int n;
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        int l, r;
        scanf("%d%d", &l, &r);
        TapeMeasure tm; 
        vector<string> ans = tm.draw(l, r);
        for(string s: ans){
            cout << s << endl;
        }

    }
}

*/
