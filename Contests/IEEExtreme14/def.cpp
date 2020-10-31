#include "bits/stdc++.h"
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 212345;
const int ZERA = INT_MAX;

int n, m, k;
int s[MAXN];

struct STree { // persistent segment tree for min over integers
    vector<int> mn, mx, mnId, mxId;
	vector<int> L, R; int n,sz,rt;
	STree(int n): mn(1,INT_MAX),mx(1,INT_MIN),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(int a, int aId, int b, int bId, int l=0, int r=0){
		int ks=mn.size();
        mn.pb(a); mnId.pb(aId);
        mx.pb(b); mxId.pb(bId);
		L.pb(l);R.pb(r);
		return ks;
	}
	/*int init(int s, int e, int *a){ // not necessary in most cases
		if(s+1==e)return new_node(a[s]);
		int m=(s+e)/2,l=init(s,m,a),r=init(m,e,a);
		return new_node(oper(st[l],st[r]),l,r);
	}*/

    
    pii mxJoin(pii a, pii b){
        if(a.fst > b.fst)
            return a;
        else
            return b;
    }
    pii mnJoin(pii a, pii b){
        if(a.fst > b.fst)
            return b;
        else
            return a;
    }

	int upd(int k, int s, int e, int p, int v, int id){
		int ks=new_node(mn[k], mnId[k], mx[k], mxId[k],L[k],R[k]);
        if(s+1==e){
            if(v == ZERA){
                mn[ks] = INT_MAX;
                mx[ks] = INT_MIN;
                mnId[ks] = -1;
                mxId[ks] = -1;
            }
            else{
                mn[ks] = mx[ks] =v; 
                mnId[ks] = mxId[ks] = id; 
            }
            return ks;
        }
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v,id),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v,id),R[ks]=ps;
        tie(mn[ks], mnId[ks]) = mnJoin({mn[L[ks]], mnId[L[ks]]}, {mn[R[ks]], mnId[R[ks]]});
        tie(mx[ks], mxId[ks]) = mxJoin({mx[L[ks]], mxId[L[ks]]}, {mx[R[ks]], mxId[R[ks]]});
		return ks;
	}

    pii qryMx(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return {INT_MIN, -1};
		if(a<=s&&e<=b)return {mx[k], mxId[k]};
		int m=(s+e)/2;
		return mxJoin(qryMx(L[k],s,m,a,b),qryMx(R[k],m,e,a,b));
    }
    pii qryMn(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return {INT_MAX, -1};
		if(a<=s&&e<=b)return {mn[k], mnId[k]};
		int m=(s+e)/2;
		return mnJoin(qryMn(L[k],s,m,a,b),qryMn(R[k],m,e,a,b));
    }
	//int init(int *a){return init(0,n,a);}
	int upd(int k, int p, int v, int id){return rt=upd(k,0,n,p,v,id);}
	int upd(int p, int v, int id){return upd(rt,p,v);} // update on last root
    // ate exclusivo
    pii qmx(int k, int ate) { return qryMx(k, 0, n, 0, ate); }
    // de inclusivo
    pii qmn(int k, int de) { return qryMn(k, 0, n, de, n); }
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);

STree lin(1), col(1);
vector<int> X, Y;

map<int, int> rootX, rootY;

void build(vector<tuple<int, int, int, int>> v){
    for(auto [x, y, xx, yy]: v){
        X.pb(x);
        X.pb(xx);
        Y.pb(y);
        Y.pb(yy);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    col = STree(X.size());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    lin = STree(Y.size());


    map<int, vector<tuple<int, int, int>>> ev;
    for(int i=0;i<v.size();i++){
        auto [x, y, xx, yy] = v[i];
        if(y == yy){
            ev[x].pb({0, y, i});
            ev[xx].pb({2, y, i});
        }
        else{
            ev[x].pb({1, y, 0});
        }
    }
    int lstRoot = 0;
    sort(ev.begin(), ev.end());
    ev.erase(unique(ev.begin(), ev.end()), ev.end());
    for(auto [x, tp]: ev){
        for(auto [t, y, id]: tp){
            if(t == 0){
                lstRoot = rootX[x] = col.upd(y, y, id);
            }
            else if(t == 2){
                lstRoot = rootX[x] = col.upd(y, ZERA, ZERA);
            }
            else{
                rootX[x] = lstRoot;
            }
        }
    }

    ev.clear();
    for(int i=0;i<v.size();i++){
        auto [x, y, xx, yy] = v[i];
        if(x == xx){
            ev[y].pb({0, x, i});
            ev[yy].pb({2, x, i});
        }
        else{
            ev[y].pb({1, x, 0});
        }
    }
    lstRoot = 0;
    sort(ev.begin(), ev.end());
    ev.erase(unique(ev.begin(), ev.end()), ev.end());
    for(auto [y, tp]: ev){
        for(auto [t, x, id]: tp){
            if(t == 0){
                lstRoot = rootY[y] = lin.upd(x, x, id);
            }
            else if(t == 2){
                lstRoot = rootY[y] = lin.upd(x, ZERA, ZERA);
            }
            else{
                rootY[y] = lstRoot;
            }
        }
    }
}

int move(int x, int y, int d){
    int cx = lower_bound(X.begin(), X.end(), x) - X.begin();
    if(d == 0){
        if(rootY.find(y) == rootY.end() || cx+1 == X.size())
            return -1;
        return lin.qmn(rootY[y], cx+1).second;
    }
    else if(d == 1){
        if(rootX.find(x) 
    }

}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
	}
    return 0;
}

