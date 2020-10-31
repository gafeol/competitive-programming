#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()

typedef long long ll;

#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)

#define fi first
#define se second

template<class T>
T sq(T x){
	return x*x;
}

struct pt{
	ll x, y, sign;
	pt(){}
	pt(ll _x, ll _y, ll _sign){
		x = _x, y = _y;
		sign = _sign;
	}
	ll operator ^(pt b) const{
		return x*b.y-y*b.x;
	}
	int quad() const{
		int ans = 0;
		if(x<0) ans++;
		if(y<0) ans^=1, ans+=2;
		return ans;
	}
	bool operator <(pt b) const{
		if(this->quad()==b.quad()){
		    return ((*this)^b)>0;
		}
		return this->quad()<b.quad();
	}
};

struct cmp1{
bool operator ()(pt p1, pt p2){
	if(p1.quad()==p2.quad()){
	    return p1.sign<p2.sign;
	}
	return p1.quad()<p2.quad();
}
};

struct cmp2{
bool operator ()(pt p1, pt p2){
	if(p1.quad()==p2.quad()){
	    return p1.sign>p2.sign;
	}
	return p1.quad()<p2.quad();
}
};

bool check(vector<pt> v){
	int i = 0;
	int n = sz(v);
	while(i<n and v[i].sign==-1) i++;
	while(i<n and v[i].sign==1) i++;
	while(i<n and v[i].sign==-1) i++;
	return i==n;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	
	fr(tt,t){
		ll n; cin >> n;
		vector<pt> v;
		fr(i,n){
			double xx, yy; cin >> xx >> yy;
			ll sign; cin >> sign;
			v.emplace_back((ll)(xx*100+0.5),(ll)(yy*100+0.5),sign);
		}
		
		sort(all(v),cmp1());
		
		int i = 0;
		
		while(i<n and v[i].sign==-1) i++;
		
		sort(v.begin()+i,v.end(),cmp2());
		
		int ok = 0;
		if(check(v)) ok = 1;
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}
