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

const int MAXN = 2000006;

int n, m, k;

vector<int> ff;
vector<char> ans;

void prep_cin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main (){
	bool end = false;
	while(!end && scanf("%d", &n)!= EOF){
		string pal;
		cin >> pal;
		int sz = pal.size();
		pal += '$';
		getchar();
		for(int a=0;a<n;a++){
			pal.resize(sz+1);
			ans.clear();
			ff.clear();
			char c;
			while((c = getchar()) != '\n' && c != EOF)
				pal.pb(c);
			//fgets(line, 2000009, stdin); 
			//int tam  = strlen(line);
			//for(int a=0;a<tam;a++)
				//pal.pb(line[a]);
			if(c == EOF)
				end = true;
			else
				pal.pb(c);
			ff.pb(-1);
			ans.pb(pal[0]);
			for(int a=1;a<pal.size();a++){
				ans.pb(pal[a]);
				int aa = ff.back();	
				while(aa >= 0 && ans[aa+1] != pal[a])
					aa = ff[aa];
				if(ans[aa+1] == pal[a]) ff.pb(aa+1);
				else
					ff.pb(aa);
				if(ff.back() == sz-1){
					int cnt = sz;
					while(cnt--){
						ff.pop_back();
						ans.pop_back();
					}
				}
			}
			for(int a=sz+1;a<ans.size();a++)
				printf("%c", ans[a]);
		}
	}
}

