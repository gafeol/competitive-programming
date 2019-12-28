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
int s[MAXN];
int o[MAXN];

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        o[a] = c-'0';
        s[a] = o[a];
        if(a >= k)
            s[a] = s[a-k];
	}
    bool men = false;
    for(int a=0;a<n;a++){
        if(s[a] < o[a])
            men = true;
        else if(s[a] > o[a])
            break;
    }
    int crr = 0;
    if(men){
        for(int a=k-1;a<n;a+=k)
            s[a]++;
        for(int a=n-1;a>=0;a--){
            if(s[a] > 9){
                s[a]-= 10;
                if(a > 0)
                    s[a-1]++;
                else
                    crr=1;
            }
        }
        for(int a=k;a<n;a++){
            s[a] = s[a-k];
        }
    }
    printf("%d\n", crr + n);
    if(crr)
        printf("1");
    for(int a=0;a<n;a++){
        printf("%d", s[a]);
    }
    puts("");
}

