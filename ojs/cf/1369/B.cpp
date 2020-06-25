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
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        vector<int> s, v;
        int pri = n;
        int lst = -1;
        for(int a=0;a<n;a++){
            char c;
            scanf(" %c", &c);
            int x = c-'0';
            s.pb(x);
            if(x)
                pri = min(pri, a);
            else
                lst = max(lst, a);
        }
        if(pri < lst){
            for(int a=0;a<pri;a++)
                printf("%d", s[a]);
            for(int a=lst;a<s.size();a++)
                printf("%d", s[a]);
            puts("");
        }
        else{
            for(int x: s)
                printf("%d", x);
            puts("");
        }
    }
}

