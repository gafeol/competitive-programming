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

int n, k;
int s[MAXN];

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

vector<pii> pos;
vector<int> let;
int mrk[MAXN];

int m[30][30];

bool ok(){
    return (m[1][1] + m[1][3] + m[1][5] + m[1][7] == 26 &&
            m[3][1] + m[3][3] + m[3][5] + m[3][7] == 26 &&
            m[0][4] + m[1][3] + m[2][2] + m[3][1] == 26 &&
            m[0][4] + m[1][5] + m[2][6] + m[3][7] == 26 &&
            m[1][1] + m[2][2] + m[3][3] + m[4][4] == 26 &&
            m[1][7] + m[2][6] + m[3][5] + m[4][4] == 26);
}

int main (){
	for(int a=0;a<5;a++){
        for(int b=0;b<9;b++){
            char c; 
            scanf(" %c", &c);
            if(c == '.') continue;
            if(c == 'x'){
                pos.pb(pii(a, b));
            }
            else{
                mrk[c] = 1;
                m[a][b] = c - 'A' + 1;
            }
        }
	}
    for(int a='A';a<='L';a++){
        if(!mrk[a])
            let.pb(a-'A'+1);
    }
    do{
        for(int i=0;i<let.size();i++){
            m[pos[i].fst][pos[i].snd] = let[i];
        }
        if(ok()){
            for(int a=0;a<5;a++){
                for(int b=0;b<9;b++){
                    if(m[a][b] == 0)
                        printf(".");
                    else
                        printf("%c", 'A'-1+m[a][b]);
                }
                puts("");
            }
            return 0;

        }

    }while(next_permutation(let.begin(), let.end()));
}

