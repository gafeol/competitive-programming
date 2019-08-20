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
ll s[MAXN];

map<int, int> cnt;

int main (){
    const string A = "sjfnb";
    const string B = "cslnb";
	scanf("%d", &n);
    int np = 0;
	for(int a=0;a<n;a++){
        scanf("%lld", s+a);
        cnt[s[a]]++;
        np += (cnt[s[a]] > 1);
    }
    if(np > 1 || cnt[0] > 1){
        cout << B << endl;
        return 0;
    }

    for(int a=0;a<n;a++){
        if(cnt[s[a]] > 1 && (cnt[s[a]-1] != 0 || s[a] == 0)){
            cout << B << endl;
            return 0;
        }
    }
    
    sort(s, s+n);
    ll sum = 0;
    for(int a=0;a<n;a++){
        sum += s[a] - a; 
    }
    if(sum&1)
        cout << A << endl;
    else
        cout << B << endl;

}

