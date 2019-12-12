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

const int MAXN = 412345;

int n, m, k;
int s[MAXN];

int main (){
    for_tests(t, tt){
        scanf("%d", &n);
        for(int a=0;a<n;a++)
            scanf("%d", s+a);
        int lst = n/2-1;
        while(lst >= 0 && s[lst] == s[lst+1])
            lst--;
        if(lst < 0){
            puts("0 0 0");
            continue;
        }
        int cnt = 1;
        int i = 1;
        while(i <= lst && s[i] == s[i-1]){
            cnt++;
            i++;
        }

        if(i > lst){
            puts("0 0 0");
            continue;
        }

        int cnt2 = 0;
        while(i <= lst && cnt2 <= cnt){
            cnt2++;
            i++;
            while(i <= lst && s[i] == s[i-1]){
                cnt2++;
                i++;
            }
        }
        if(cnt2 <= cnt){
            puts("0 0 0");
            continue;
        }

        int cnt3 = lst - i + 1;
        if(cnt3 <= cnt){
            puts("0 0 0");
            continue;
        }

        printf("%d %d %d\n", cnt, cnt2, cnt3);
    }
}

