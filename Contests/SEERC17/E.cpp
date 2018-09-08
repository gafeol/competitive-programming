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

const int MAXN = 10000007;

int n, m, k;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int mrk[(1<<12)+1];
int s[MAXN];
char pal[10];

inline int f(){
	int sz = strlen(pal);
	int ans = 0;
	char c = pal[0];
	if(c == 'D')
		ans = 0;
	else if(c == 'R')
		ans = 2;
	else if(c == 'M')
		ans = 4;
	else if(c == 'F')
		ans = 5;
	else if(c == 'S' && pal[1] == 'o')
		ans = 7;
	else if(c == 'L')
		ans = 9;
	else if(c == 'S' && pal[1] == 'i')
		ans = 11;
	if(pal[sz-1] == '#')
		ans++;
	return ans;
}

int pls[] = {0, 2, 4, 5, 7, 9, 11};

int msk[20];

inline int go(int i, int j){
	int bmm = 0;
	int res = 0;
	for(int a=i;a<=j;a++){
		int nbm = bmm|(1<<s[a]);
		if(!mrk[nbm]){
			res++;
			bmm = 0;
			nbm = (1<<s[a]);
		}
		bmm = nbm;			
	}
	if(bmm != 0) res++;
	return res;	
}

void read(){
	int cnt = 0;
	char c;
	while((c = getchar()) != '\n' && c != EOF){
		pal[cnt++] = c;
	}
	pal[cnt] = '\0';
}

int main (){
	scanf("%d", &n);
	getchar();
	for(int a=0;a<n;a++){
		read();
		s[a] = f();
	}
	for(int a=0;a<12;a++){
		int bm = 0;
		for(int ch=0;ch<(1<<7);ch++){
			bm = 0;
			for(int b=0;b<7;b++){
				if(!(ch&(1<<b))) continue;
				int i = (a + pls[b])%12;	
				bm |= (1<<i);
			}
			mrk[bm] = 1;
		}
		msk[a] = bm;
	}
	int res = go(0, n-1);
	for(int a=0;a<12;a++){
		int i = 0;
		int j = n-1;
		int cnt = 0;
		int bmm = 0;
		while(i <= j && (msk[a]&(1<<s[i]))){
			bmm |= (1<<s[i]);
			i++;
			cnt++;
		}
		while(i <= j && (msk[a]&(1<<s[j]))){
			bmm |= (1<<s[j]);
			j--;
			cnt++;
		}
		if(cnt > 1){
			res = min(res, 1 + go(i, j));	
		}
	}
	printf("%d\n", res);
}

