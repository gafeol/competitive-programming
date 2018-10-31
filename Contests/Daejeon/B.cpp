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
const int INF = 0x3f3f3f3f;
const int BM = 3*3*3*3;

int n, m, k;
int s[MAXN];
bool d[5][BM][BM][BM][BM];
bool j[5][BM][BM][BM][BM];

queue<tuple<int, int, int, int, int> > q;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int pot[6];

bool foi(int a, int b, int c){
    int m[4][3];    
    for(int i=0;i<4;i++){
        m[i][0] = a%3;
        a/=3;
    }
    for(int i=0;i<4;i++){
        m[i][1] = b%3;
        b/=3;
    }
    for(int i=0;i<4;i++){
        m[i][2] = c%3;
        c/=3;
    }
    /*
    puts("TESTA:");
    for(int a=0;a<4;a++){
        for(int b=0;b<3;b++){
            printf("%d ", m[a][b]);
        }
        puts("");
    }
    */

    for(int t=1;t<=2;t++){
        for(int i=0;i<4;i++){
            int cnt = 0;
            for(int j=0;j<3;j++){
                cnt += (m[i][j] == t);
            }
            if(cnt == 3) return true;
        }
        for(int j=0;j<3;j++){
            int cnt = 0;
            for(int i=0;i<3;i++){
                cnt += (m[i][j] == t);
            }
            if(cnt == 3) return true;
            cnt = 0;
            for(int i=1;i<4;i++){
                cnt += (m[i][j] == t);
            }
            if(cnt == 3) return true;
        }
        if(m[0][0] == t && m[1][1] == t && m[2][2] == t) return true;
        if(m[1][0] == t && m[2][1] == t && m[3][2] == t) return true;
        if(m[2][0] == t && m[1][1] == t && m[0][2] == t) return true;
        if(m[1][2] == t && m[2][1] == t && m[3][0] == t) return true;
    }
   // puts("FALSO");
    return false;
}

bool acabou(int* qtd){
    //printf("end %d %d %d %d\n", qtd[1], qtd[2], qtd[3], qtd[4]);
    return (foi(qtd[1], qtd[2], qtd[3]) ||
            foi(qtd[2], qtd[3], qtd[4]));
}

int lg(int x){
    int ans = 0;
    while(x > 0){
        ans++;
        x /= 3;
    }
    return ans;
}

int main (){
    pot[0] = 1;
    for(int a=1;a<=5;a++)
        pot[a] = 3*pot[a-1];

    int x;
	scanf("%d", &x);
    scanf("%d%d", &n, &m);
    q.push({x, (1 == x), (2 == x), (3 == x), (4 == x)});
    d[x][(1 == x)][(2 == x)][(3 == x)][(4 == x)] = 1;
    int res = 0;
    while(!q.empty()){
        int j, qtd[5];
        tie(j, qtd[1], qtd[2], qtd[3], qtd[4]) = q.front();
        //printf("j %d %d %d %d %d\n", j, qtd[1], qtd[2], qtd[3], qtd[4]);
        bool jog = ::j[j][qtd[1]][qtd[2]][qtd[3]][qtd[4]];
        if(acabou(qtd) && (qtd[j]/pot[n-1]) == 2 && j == m)
            res++;
        q.pop();
        if(acabou(qtd)) continue;

        for(int a=1;a<=4;a++){
            int h = lg(qtd[a]);
            if(h + 1 <= 4){
                int oldq = qtd[a];
                qtd[a] += pot[h]*((jog^1) + 1);
                if(d[a][qtd[1]][qtd[2]][qtd[3]][qtd[4]] == 0)
                    q.push({a, qtd[1], qtd[2], qtd[3], qtd[4]});
                d[a][qtd[1]][qtd[2]][qtd[3]][qtd[4]] = 1;
                ::j[a][qtd[1]][qtd[2]][qtd[3]][qtd[4]] = (jog^1);
                qtd[a] = oldq; 
            }
        }
    }
    printf("%d\n", res);
}

