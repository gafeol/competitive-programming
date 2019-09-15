#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#ifndef ONLINE_JUDGE
#define debug(args...) fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 212345;

int n, m, k;
string bp, bs, p, s;

string pat;
ll lo, o;

// Z Algorithm
//////////////
const int MAXS = MAXN*2;

int L, R, Z[MAXS];


inline void ZAlgorithm(string s){
	int tam = s.size();
	L = R = 0;
	for(int i=1;i<tam;i++){
		if(i > R){
			L = R = i;
			while(R < tam && s[R] == s[R-L])
				R++;
			Z[i] = R-L; 
			R--;
		}
		else{
			if(Z[i-L] >= R-i+1){
				L = i;
				while(R < tam && s[R] == s[R-L])
					R++;
				Z[i] = R-L;
				R--;
			}
			else
				Z[i] = Z[i-L];
		}
	}
}

// numero de occorencias de p em s
int occ(string s, string p){
    //cout << "count occ of " << p << " in " << s << endl;
    ZAlgorithm(p+"$"+s);
    int ans = 0;
    for(int i=p.size();i<p.size()+1+s.size();i++){
        ans += (Z[i] == p.size());  
    }
    //printf("%d occ\n", ans);
    return ans;
}

int main (){
    int tt = 1;
    while(scanf("%d\n", &n) != EOF){
        cin >> pat;

        printf("Case %d: ", tt++);
        if(n == 0){
            if(pat == "0")
                puts("1");
            else
                puts("0");
            continue;
        }
        else if(n == 1){
            if(pat == "1")
                puts("1");
            else
                puts("0");
            continue;
        }
        
        int nn = 2;
        bp = bs = (pat.size() > 1 ? "0" : "");
        lo = (pat == "0" ? 1 : 0);
        p = s = (pat.size() > 1 ? "1" : "");
        o = (pat == "1" ? 1 : 0);

        while(nn <= n){
            int len = min(bp.size() + p.size(), pat.size()-1);
            string np = (p + bp).substr(0, len);
            ///printf("n %d\n", nn);
            ///cout << "new pref " << np << endl;
            len = min(bs.size() + s.size(), pat.size()-1);
            string ns = (s + bs).substr((bs.size()+s.size() - len), len);
            ///cout << "new suff " << ns << endl;

            ll no = lo + o + (ll)occ(s+bp, pat);
            ///printf("no %lld\n", no);
            bp = p;
            bs = s;
            lo = o;

            p = np;
            s = ns;
            o = no;
           
            nn++;
              
        }
        printf("%lld\n", o);

    }
}

