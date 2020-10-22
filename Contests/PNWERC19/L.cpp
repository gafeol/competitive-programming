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
char num[30];
vector<int> s;
int c[30];

bool check(int i){
    int sum[30];
    for(int a=0;a<=i+1;a++){
        sum[a] = 0;
    }
    for(int f=0;f<=i;f++){
        for(int o=0;f + o < i+1 && o<=i;o++){
            sum[o+f] = (sum[o+f] + c[o]*c[f])%10;
        }
    }
    for(int a=0;a<=i;a++){
        if(sum[a] != s[a])
            return false;
    }
    return true;
}

ll res;

bool checkTotal(){
    int sum[30];
    for(int a=0;a<n;a++)
        sum[a] = 0;
    for(int f=0;f<k;f++){
        for(int o=0;o<k;o++){
            sum[o+f] = (sum[o+f] + c[o]*c[f])%10;
        }
    }
    for(int a=0;a<n;a++){
        if(sum[a] != s[a])
            return false;
    }
    ll ans = 0;
    for(int a=k-1;a>=0;a--){
        ans *= 10;
        ans += c[a];
    }
    res = min(res, ans);
    return true;
}

bool go(int i){
    if(i == k)
        return checkTotal();
    for(int d=0;d<10;d++){
        c[i] = d;
        if(!check(i))
            continue;
        go(i+1);
    }
    return false;
}

int main (){
    scanf(" %s", num);
    n = strlen(num);
    s.resize(n);
    for(int a=0;a<n;a++)
        s[a] = num[a]-'0';
    reverse(s.begin(), s.end());
    if(n%2 == 0){
        puts("-1");
        return 0;
    }
    else{
        k = (n+1)/2;
        res = LLONG_MAX;
        go(0);
        if(res == LLONG_MAX)
            puts("-1");
        else
            printf("%lld\n", res);
    }
}

