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

vector<int> np  = {6, 10, 14, 15};

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        int x;
        scanf("%d", &x);
        int o = x - np[0] - np[1] - np[2];
        int o2 = x - np[0] - np[1] - np[3];
        if(o > 0 && !(o == 6 || o == 10 || o == 14)){
            puts("YES");
            printf("%d %d %d %d\n", np[0], np[1], np[2], o);
        }
        else if(o2 > 0 && !(o2 == 6 || o2 == 10 || o2 == 15)){
            puts("YES");
            printf("%d %d %d %d\n", np[0], np[1], np[3], o2);
        }
        else
            puts("NO");
	}
}

