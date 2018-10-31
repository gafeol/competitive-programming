#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)

template <typename T> void write(ostream& out, T t) {
	out << t << "\n";
}
template <typename T, typename... Args>
void write(ostream& out, T t, Args... args) {
	out << t << ' ';
	write(out, args...);
}

template <typename... Args>
void debug(Args... args) {
	#ifdef LOCAL
		write(cerr, args...);
	#endif
}


template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	scanf("%d", &n);
    int summx = 0;
	for(int a=0;a<n;a++){
        char c;
        scanf(" %c", &c);
        s[a] = c-'0';
        summx += s[a];
	}
    for(int sum = 0;sum <= summx;sum++){
        int ate = 0;
        int ok = 1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(ate == sum){
                cnt++;
                ate = 0;
            }
            ate += s[i];  
            if(ate > sum){
                ok = 0;
                break;
            }
        }
        if(ate != sum && !(ate == 0 && cnt > 1)){
            ok = 0;
        }
        if(ok && cnt > 0){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}

