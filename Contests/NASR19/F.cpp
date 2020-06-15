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

const double pi = acos(-1);

int n, m, k;
vector<tuple<double, int, int>> ev;
vector<tuple<double, double, double>> s;

int main (){
	scanf("%d", &n);
    double res = 0;
    double val = 0;
	for(int a=0;a<n;a++){
        double t, ss, ang;
        scanf("%lf%lf%lf", &t, &ss, &ang);
        double sob = t - pi*ss;
        if(sob > 0){
           val += sob; 
           t -= sob;
        }
        s.pb({t, ss, ang});
        double the = t/ss;
        ev.pb({ang-the, 0, a});
        ev.pb({ang, 1, a});
        ev.pb({ang+the, 2, a});
        ev.pb({2*pi + ang-the, 0, a});
        ev.pb({2*pi + ang, 1, a});
        ev.pb({2*pi + ang+the, 2, a});
	}
    sort(ev.begin(), ev.end());
    double oldthe = 0;
    double ss = 0, ds = 0;
    for(tuple<double, int, int> tp : ev){
        double the;
        int t, id;
        tie(the, t, id) = tp;
        double dthe = the - oldthe;
        val += dthe*(ss-ds);
        res = max(res, val);
        if(t == 0){
            ss += get<1>(s[id]);
        }
        else if(t == 1){
            ss -= get<1>(s[id]);
            ds += get<1>(s[id]);
        }
        else{
            ds -= get<1>(s[id]);
        }
        oldthe = the;
    }
    printf("%.10f\n", res);
}

