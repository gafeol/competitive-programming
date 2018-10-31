#include <bits/stdc++.h>
using namespace std;

#define FILE_IN freopen("kotlin.in", "r", stdin);
#define FILE_OUT freopen("kotlin.out", "w", stdout);

#define fr(i,n) for(short i=0;i<n;i++)
#define frr(i,a,b) for(short i =a;i<=b;i++)
// for(auto it : g[i].nb)

typedef long long ll;

#define pb push_back

#define fi first
#define se second
typedef pair<short,short> pii;
typedef pair<ll,ll> pll;

const long double PI = acos(-1.0l);
const ll MOD = 1e9+7;

//LLONG_MAX
//-DBL_MAX
//__builtin_popcountll(ll x) - __builtin_popcount(int x)

bool debug = 1;
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define ppal(a)  if(debug) cout << #a << endl
#define prinsep if(debug) cout << "------" << endl
#define cendl if(debug) cout << endl
#define prinpar(p) if(debug) cout << #p << ".fi=" << (p).fi << " " << #p << ".se=" << (p).se << endl
#define prinv(v) if(debug){ cout << #v << ":" << endl; for(auto it = (v).begin(); it!=(v).end();it++){ cout << *it << " ";} cout << endl;}

const short N = 2e3+10;


unordered_map<short,ll> dp[N];

short n;
short maxv;

const int NN = 1e5+10;

short borig[NN];

vector<short> b;

bool ok(short id, short val, short dif){
    short soma = dif+val;
    return (soma+(n-id)*val<=maxv) and (soma<=b[id-1]);
}   

short cnt = 0;

//map<short,vector<ll>> pref[N];
//unordered_map<short,vector<ll>> pref[N];
vector<vector<ll>> pref[N];

inline ll rec(short id, short val, short dif);

//l e r vao de 0 a maxval-dif
inline ll soma(short id, short l, short r, short dif){
    while(pref[id].size()<dif+1){
        pref[id].resize(dif+1);
    }
    vector<ll> &v = pref[id][dif];
    if(v.size()<r+1){
        if(v.size()==0) v.pb(rec(id,0,dif));
        while(v.size()<r+1){
            v.pb(v.back()+rec(id,v.size(),dif));
        }
    }
    ll tira = 0;
    if(l) tira = v[l-1];
    return v[r]-tira;
}   

//estou na posicao id, sendo que ateh id-1 tenho soma e ultimo usado val
inline ll rec(int id, short val, short dif){
    if(id==n) return 1;
    if(!ok(id+1,val,dif)) return 0;
    short par = 2001*val+dif;
    if(dp[id].count(par)) return dp[id][par];
    //cnt++;
    //assert(cnt<=2e6+10);
    
    ll &ans = dp[id][par] = 0;
    
    short lo = val, hi = maxv+1;
    while(lo<hi){
       short mid = (lo+hi)/2;
       if(!ok(id+1,mid,dif+val)){
          hi = mid;
       } else lo = mid+1;
    }
    //assert(!ok(id+1,lo,dif+val));
    lo--;
    ans = (ans+soma(id+1,val,lo,dif+val))%MOD;
    /*
    frr(i,val,maxv){
        if(ok(id+1,i,dif+val)) ans = (ans+rec(id+1,i,dif+val))%MOD;
        else{
            if(i!=lo+1){
                prin(i);
                prin(lo);
                prin(maxv);
                exit(0);
            }
            
            break;
        }
    }
    */
    
    return ans;
}

int main(){
	scanf("%d", &n);
	
	fr(i,n){
	    scanf("%d", &borig[i]);
	}
	
	maxv = borig[n-1];
	
	for(short i = n-2;i>=0;i--){
	    borig[i] = min(borig[i],borig[i+1]);
	    maxv = max(maxv,borig[i]);
	}
	
	if(maxv==1){
	    cout << 1 << endl;
	    return 0;
	}
	
	for(short i = max(n-maxv,0); i<n;i++){
	    b.pb(borig[i]);
	}
	
	n = b.size();
	
	
	ll ans = rec(0,0,0);
	
	cout << ans << endl;
	
	return 0;
}

