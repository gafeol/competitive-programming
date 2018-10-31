#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
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

map<string, vector<int> > cpc;

bool cmp(int a, int b){
	return a>b;
}

bool cmp2(pis a, pis b){
	return (a.fst > b.fst || (a.fst == b.fst && a.snd < b.snd));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		vector<string> vs;
		cin >> ws;
		string t;
		getline(cin,t);
		t += '$';
		istringstream iss(t);
		int num = -1;
		bool cont = true;
		int lin = 1;
		while(cont){
			char c;
			string word;
			bool in = false;
			while((iss.get(c))){
				if(c == '$'){
					lin++;
					cont = false;
					break;
				}
				if(c == '\"'){
					if(in == true) break;
					in = true;
					continue;
				}
				if(in)
					word += c; }
			if(!(iss.get(c)) && !cont) break;
			if(word.compare("full_name") == 0){
				string name;
				char c;
				bool in = false;
				while(iss.get(c)){
					if(c == '\"'){
						if(in == true)
							break;
						in  = true;
						continue;
					}
					name += c;
				}
				vs.pb(name);
			}

			if (word.compare("citing_paper_count") == 0){
				iss >> num;
			}
		}
		if(num >= 0){
			for(string s: vs){
				cpc[s].pb(num);		
			}
		}
	}

	vector<pis> ans;
	for(auto it: cpc){
		sort(it.snd.begin(), it.snd.end(), cmp);
		int res = 0;
		for(int a=0;a<it.snd.size();a++){
			res = max(res, min(a+1, it.snd[a]));
		}
		ans.pb({res, it.fst});
	}
	sort(ans.begin(), ans.end(), cmp2);
	for(int i=0;i<(int)ans.size();i++){
		printf("%s %d\n", ans[i].snd.c_str(), ans[i].fst);
	}
}

