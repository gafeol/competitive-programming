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

const int MAXN = 2523, MAXM = 5123;

int n, m, k;
char s[MAXN][MAXM];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<int> err[MAXN];

int mrk[MAXN];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
        scanf(" %s", s[a]); 
	}
    bool eq = 0;
    for(int a=0;a<m;a++)
        eq = max(eq, (++mrk[s[0][a]] > 1));

    for(int i=1;i<n;i++){
        for(int a=0;a<m;a++){
            if(s[0][a] != s[i][a])
                err[i].pb(a);
        }
        if(err[i].size() > 4){
            puts("-1");
            return 0;
        }
    }
    for(int a=0;a<m;a++){
        for(int b=a+1;b<m;b++){
            swap(s[0][a], s[0][b]);
            //printf("test %s\n", s[0]);
            for(int i=1;i<=n;i++){
                if(i == n){
                    printf("%s\n", s[0]); 
                    return 0;
                }
                if(err[i].empty()) continue;
                vector<int> pos;
                for(int p: err[i]){
                    //printf("i %d test %d\n", i, p);
                    if(s[i][p] !=  s[0][p]){
                        //printf("i %d err %d\n", i, p);
                        pos.pb(p);
                    }
                }
                if(s[0][a] != s[0][b]){
                    if(s[i][a] != s[0][a])
                        pos.pb(a);
                    if(s[i][b] != s[0][b])
                        pos.pb(b);
                }
                sort(pos.begin(), pos.end());
                pos.erase(unique(pos.begin(), pos.end()), pos.end());
                //printf("pos sz %d\n", (int)pos.size());
                if(pos.size() == 0){
                    if(eq) continue;
                    else break;
                }
                if(pos.size() != 2) break;
                if(s[0][pos[0]] != s[i][pos[1]] || s[0][pos[1]] != s[i][pos[0]]) break; 
            }
            swap(s[0][a], s[0][b]);
        }
    }
    puts("-1");

}

