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

const int MAXN = 212345;

int n, m, k;
char s[MAXN];
int cnt[10];

void win(int x){
    printf("%d\n", x);
    exit(0);
}

void fail(){
    puts("-1");
    exit(0);
}

int main (){
    scanf(" %s", s);
    n = strlen(s);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += s[i]-'0';
        cnt[(s[i]-'0')%3]++;
    }
    if(sum%3 == 0){
        win(0);
    }
    if(n == 1)
        fail(); 
    if(cnt[sum%3])
        win(1);
    if(n == 2 || cnt[(2*sum)%3] < 2)
        fail();
    win(2);
    return 0;
}

