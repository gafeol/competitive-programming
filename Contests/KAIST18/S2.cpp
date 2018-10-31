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
char s[MAXN];

map<string, int> ind;

int F[10], R[10];

map<int, map<int, string> > ans;

void go(int f, int r){
	//printf("go %d %d\n", f, r);
	if(f == 0){
		puts("None");
		return ;
	}
	int indf = 0;
	while(indf < 4 && F[indf] < f)
		indf++;
	int indr = 0;
	while(indr < 4 && R[indr] < r)
		indr++;
	//printf("indf %d indr %d\n", indf, indr);
	
	cout << ans[indf][indr] << endl;
}

int lst[MAXN], cnt[MAXN];

int main (){
	ans[0][0] = "New Customer";
	ans[0][1] = "Promising";
	ans[0][2] = "About to Sleep";
	ans[0][3] = "Lost";
	ans[0][4] = "Lost";

	ans[1][0] = "Potential Loyalist";
	ans[1][1] = "Potential Loyalist";
	ans[1][2] = "About to Sleep";
	ans[1][3] = "Hibernating";
	ans[1][4] = "Lost";

	ans[2][0] = "Potential Loyalist";
	ans[2][1] = "Potential Loyalist";
	ans[2][2] = "Need Attention";
	ans[2][3] =	"About to Leave";
	ans[2][4] = "About to Leave";

	ans[3][0] = "Loyal Customer";
	ans[3][1] = "Loyal Customer";
	ans[3][2] = "Loyal Customer";
	ans[3][3] = "About to Leave";
	ans[3][4] = "About to Leave";

	ans[4][0] = "Champion";
	ans[4][1] = "Loyal Customer";
	ans[4][2] = "Loyal Customer";
	ans[4][3] = "About to Leave";
	ans[4][4] = "Can't Lose Them";

	for(int a=0;a<4;a++){
		scanf("%d", F+a);
	}
	for(int a=0;a<4;a++){
		scanf("%d", R+a);
	}

	scanf("%d", &n);
	int id = 0;
	for(int a=0;a<n;a++){
		int t;
		scanf("%d %s", &t, s);
		int is;
		if(ind.find(s) == ind.end())
			ind[s] = id++;
		is = ind[s];
		if(t == 1){
			cnt[is]++;
			lst[is] = a;
		}
		else{
			go(cnt[is], a - lst[is]);
		}
	}
}

