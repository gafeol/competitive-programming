#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, int> pid;
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

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

char s[MAXN][30];
double A[MAXN], B[MAXN];

set<pid> q;

vector<pid> rmv;
int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
        scanf(" %s %lf %lf", s[a], A+a, B+a);
        q.insert(pid(B[a], a));
	}
    double res = DBL_MAX;
    for(int a=0;a<n;a++){
       double ans = A[a]; 
       int cnt = 0;
       while(cnt < 3){
            pid t = *q.begin();
            q.erase(t);
            rmv.pb(t);
            if(t.snd == a) continue;
            cnt++;
            ans += t.fst;
       }
       res = min(res, ans);

       for(pid p: rmv)
           q.insert(p);
        rmv.clear();
    }

    printf("%.10f\n", res);
    for(int a=0;a<n;a++){
        double ans = A[a];
        int cnt = 0;
        while(cnt<3){
            pid t = *q.begin();
            q.erase(t);
            rmv.pb(t);
            if(t.snd == a) continue;
            cnt++;
            ans += t.fst;

        }

        if(ans == res){
            printf("%s\n", s[a]);
            for(pid p: rmv){
                int ind = p.snd;
                if(ind == a) continue;
                printf("%s\n", s[ind]);
            }
            return 0;
        }
       for(pid p: rmv)
           q.insert(p);
        rmv.clear();
    }
}

