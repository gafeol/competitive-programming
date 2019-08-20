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
char s[MAXN];

int main (){
    scanf(" %s", s);
    int tam = strlen(s);
    if(tam == 1 && s[0] == '0'){
        puts("0");
        return 0;
    }
    int lst = -1, ans = 0;
    for(int i = tam-1;i >= 0;i-=2){
        ans++;
        lst = i;
    }

    int cnt = 0;
    for(int i=0;i<tam;i++){
        cnt += (s[i] == '1'); 
    }

    if(lst == 0 && cnt == 1)
        ans--;

    printf("%d\n", ans);
}

