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


map<char, ll> cnts;
map<char, ll> cntc;
vector<pair<char, char> > cards;

ll val = 0;
ll v(char c){
	if(c == '1' || c == 'J' || c == 'Q' || c == 'K' || c == 'A')
		return 10;
	return c - '0';
}

char sq[] = {'2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K', 'A'};

bool hasst(){
	int n = strlen(sq);	
	for(int a=0;a+4<n;a++){
		bool ok = true;
		for(int i=0;i<5;i++){
			if(cntc[sq[a+i]] == 0){
				ok = false;
				break;
			}
		}
		if(ok) 
			return true;
	}
	return false;
}


int nmod, lstmod;

void go(int r){
	int oldval = val;
	if(r == 1){
		val += 1;
		val += cntc['J']*v(cards[0].fst);
	}
	else if(r == 2){
		ll mx = -1;
		for(auto it: cnts)
			mx = max(mx, it.snd);
		if(mx >= 2){
			val = val*2ll;
		}
	}
	else if(r == 3){
		ll mn = min(min(cnts['C'], cnts['S']), min(cnts['D'], cnts['H']));
		if(mn > 0){
			val*=2;
		}
	}
	else if(r == 4){
		ll cp = cnts['C'] + cnts['S'];
		ll cv = cnts['D'] + cnts['H'];
		if(cp != cv){
			val += abs(cp - cv);
		}
	}
	else if(r == 5){
		if(!(val&1)){
			vector<ll> ans;
			for(ll a=1;a<=sqrt(abs(val))+2;a++){
				if(val%a != 0) continue;	
				ans.pb(a);
				ans.pb(abs(val/a));
			}
			sort(ans.begin(), ans.end());
			ans.erase(unique(ans.begin(), ans.end()), ans.end());
			for(ll x: ans)
				val += x;
		}
	}
	else if(r == 6){
		if(cntc['7'] == 4){
			val -= 11*11;
		}
	}
	else if(r == 7){
		if(val >= 0){
			ll mn = INT_MAX;
			for(auto it: cards){
				mn= min(mn, v(it.fst));
			}
			val += mn;
		}
	}
	else if(r == 8){
		if(val < 0){
			val *= -1;
		}
	}
	else if(r == 9){
		if(cnts['D'] >= 3){
			val++;
			vector<pair<char, char> > nv;
			for(auto it: cards){
				if(it.fst == '6'){
					nv.pb({'9', it.snd});
				}
				else if(it.fst == '9'){
					nv.pb({'6', it.snd});
				}
				else if(it.fst == '2'){
					nv.pb({'5', it.snd});
				}
				else if(it.fst == '5'){
					nv.pb({'2', it.snd});
				}
				else
					nv.pb(it);
			}
			cnts.clear();
			cntc.clear();
			cards = nv;
			for(auto it: cards){
				cntc[it.fst]++;
				cnts[it.snd]++;
			}
		}
	}
	else if(r == 10){
		if(hasst()){
			val += 5ll*cntc['A'];	
		}
	}
	else if(r == 11){
		if(nmod > 8){
			val += __builtin_popcountll(val);
		}
	}
	else if(r == 12){
		if(cntc['2'] >= 1){
			go(lstmod);
		}
	}
	else if(r == 13){
		if(cntc['2'] >= 1){
			val = val*2ll;
		}
	}

	if(val != oldval){
		nmod++;
		lstmod = r;
	}
}

int main (){
	for(int a=0;a<5;a++){
		char c, s;
		char pal[4];
		scanf(" %s", pal);
		c = pal[0];
		s = pal[strlen(pal)-1];
		cards.pb({c, s});
		val += v(c);
		cntc[c]++;
		cnts[s]++;
	}

//	printf("val %lld\n", val);
	for(int a=1;a<=13;a++){
		go(a);
//		printf("a %d val %lld\n", a, val);
	}
	printf("%lld\n", val);
}

