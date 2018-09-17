
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

vector<int> pos, neg, zer;

bool cmp(int a, int b){
    return s[a] > s[b];
}

int main (){
	scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%d", s+a);
        if(s[a] > 0)
            pos.pb(a);
        else if(s[a] == 0)
            zer.pb(a);
        else
            neg.pb(a);
    }
    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);
    int in = 0;
    int ult = -1;
    for(int a=0;a<zer.size();a++){
        ult = zer[a];
        if(a + 1 < zer.size()){
            printf("1 %d %d\n", zer[a]+1, zer[a+1]+1);
            n--;
        }
    }
    if((neg.size()&1)){
        if(ult != -1){
            printf("1 %d %d\n", ult+1, neg[0]+1);
            n--;
        }
        ult = neg[0];
        in++;
    }
    if(n > 1 && ult >= 0){
        printf("2 %d\n", ult+1); 
        n--;
    }
    vector<int> mult;
    for(int a=0;a<pos.size();a++)
        mult.pb(pos[a]);
    for(int a=in;a<neg.size();a++)
        mult.pb(neg[a]);
    for(int a=0;a<mult.size();a++){
        if(a + 1 < mult.size()){
            printf("1 %d %d\n", mult[a]+1, mult[a+1]+1);
        }
    }
}
