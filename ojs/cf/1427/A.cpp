#include "bits/stdc++.h"
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
bool test(vector<int> s){
    int som = 0;
    for(int i=0;i<s.size();i++){
        som += s[i];
        if(som == 0)
            return false;
    }
    puts("YES");
    for(int x: s){
        printf("%d ", x);
    }
    puts("");
}

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        vector<int> s(n);
        int som = 0;
        for(int a=0;a<n;a++){
            scanf("%d", &s[a]);
        }
        sort(s.begin(), s.end(), greater<int>());
        if(test(s))
            continue;
        sort(s.begin(), s.end());
        if(test(s))
            continue;
        puts("NO");
    }
}

