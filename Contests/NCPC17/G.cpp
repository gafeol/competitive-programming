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

int np[MAXN], p[MAXN];

multiset<pii> q;

bool isbest(pii i){
    return i < pii(-np[0], p[0]);
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
        int i,j;
        scanf("%d%d", &i, &j);
        i--;
        if(i != 0){
            if(isbest(pii(-np[i], p[i])))
                q.erase(q.find(pii(-np[i], p[i])));
            np[i]++;
            p[i] += j;
            if(isbest(pii(-np[i], p[i])))
                q.insert(pii(-np[i], p[i]));
        }
        else{
            np[i]++;
            p[i]+=j;
            while(!q.empty() && !isbest(*q.rbegin()))
                q.erase(q.find(*q.rbegin()));
        }
        printf("%d\n",1+ (int)q.size());
	}
}

