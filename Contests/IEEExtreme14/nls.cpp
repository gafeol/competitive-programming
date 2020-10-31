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
	void print(){
		cout << x << " " << y << " " << sign << "\n";
	}
};

struct cmp1{
bool operator ()(pt p1, pt p2){
	if(p1.quad()==p2.quad()){
		if( (p1^p2)!=0) return (p1^p2)>=0;
	    return p1.sign<p2.sign;
	}
	return p1.quad()<p2.quad();
}
};

bool ig(pt p1, pt p2){
	return p1.quad()==p2.quad() and (p1^p2)==0;
}

struct cmp2{
bool operator ()(pt p1, pt p2){
	if(p1.quad()==p2.quad()){
		if( (p1^p2)!=0) return (p1^p2)>=0;
	    return p1.sign>p2.sign;
	}
	return p1.quad()<p2.quad();
}
};

bool check2(vector<pt> v){
	int i = 0;
	int n = sz(v);
	while(i<n and v[i].sign==1) i++;
	while(i<n and v[i].sign==-1) i++;
	while(i<n and v[i].sign==1) i++;
	return i==n;
}

bool check1(vector<pt> v){
	int i = 0;
	int n = sz(v);
	while(i<n and v[i].sign==-1) i++;
	while(i<n and v[i].sign==1) i++;
	while(i<n and v[i].sign==-1) i++;
	return i==n;
}

bool brute(vector<pt> v){	
	int ok = 0;
	if(sz(v)==0) return 1;
	for(auto &pivo : v){
		int tdig = 1, tddif = 1;
		for(auto &it : v){
			if((pivo^it)==0) continue;
			if(! ((pivo^it)>0 == (it.sign>0))) tdig = 0;
			if(! ((pivo^it)>0 != (it.sign>0))) tddif = 0;
		}
		if(tdig or tddif) ok = 1;
	}
	return ok;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	
	fr(tt,t){
		ll n; cin >> n;
		vector<pt> v;
		
		if(n<=5000){
			fr(i,n){
				double xx, yy; cin >> xx >> yy;
				ll sign; cin >> sign;
				ll x = (ll)(xx*100+0.5);
				ll y = (ll)(yy*100+0.5);
				if(x==0 and y==0) continue;
				
				v.emplace_back(x,y,sign);
			}
			if(brute(v)){
				cout << "YES\n";
			} else{
				cout << "NO\n";
			}	
			continue;
		}
		
		int tdm1 = 1;
		int td1 = 1;
		fr(i,n){
			double xx, yy; cin >> xx >> yy;
			ll sign; cin >> sign;
			ll x = (ll)(xx*100+0.5);
			ll y = (ll)(yy*100+0.5);
			
			if(x==0 and y==0) continue;
			
			if(sign==-1) td1 = 0;
			if(sign==1) tdm1 = 0;
			v.emplace_back(x,y,sign);
		}
		
		
		
		int ok = 0;
		
		int td = 1;
		fr(i,sz(v)){
			if(!ig(v[0],v[i])) td = 0;
		}
		if(td) ok = 1;
		
		if(td1 or tdm1){
			
			if(sz(v)<=2) ok = 1;
			else{
				sort(all(v),cmp1());
				fr(i,sz(v)){
					int p1 = (i+1)%sz(v);
					if( (v[i]^v[p1])<0) ok = 1;
					if( (v[i]^v[p1])==0 and v[i].quad()!=v[p1].quad() ) ok = 1;
					
				}
				
				
			}
		} else{
		
		{
			sort(all(v),cmp1());
			
			int i = 0;
			
			/*
			for(auto &it : v){
				it.print();
			}*/
			
			while(i<n and v[i].sign==-1) i++;
			
			//prin(i);
			
			sort(v.begin()+i,v.end(),cmp2());
			
			if(check1(v)){
				//prin(sz(v));
				int p1 = i;
				int p2 = i;
				while(p2<sz(v) and v[p2].sign==1) p2++;
				p2--;
				
				//prin(p1);
				//prin(p2);
				
				
				
				int pm1 = (p2+1)%sz(v);
				int pm2 = (p1-1+sz(v))%sz(v);
				
				//prin(pm1);
				//prin(pm2);
				if((v[p1]^v[p2])>=0 and (v[pm1]^v[pm2])>=0) ok = 1;
			}
		}
		
		{
			sort(all(v),cmp2());
			
			int i = 0;
			
			while(i<n and v[i].sign==1) i++;
			
			sort(v.begin()+i,v.end(),cmp1());
			
			if(check2(v)){
				int p1 = i;
				int p2 = i;
				while(p2<sz(v) and v[p2].sign==-1) p2++;
				p2--;
				
				int pm1 = (p2+1)%sz(v);
				int pm2 = (p1-1+sz(v))%sz(v);
				if((v[p1]^v[p2])>=0 and (v[pm1]^v[pm2])>=0) ok = 1;
			}
		
		}
		
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}
