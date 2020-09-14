#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

template<class T = int>
struct Bit2D {
public:
	Bit2D(vector<pair<T, T>> pts) {
		sort(pts.begin(), pts.end());
		for(auto a : pts) {
			if(ord.empty() || a.first != ord.back()) {
				ord.push_back(a.first);
			}
		}
		fw.resize(ord.size() + 1);
		coord.resize(fw.size());
		for(auto &a : pts) {
			swap(a.first, a.second);
		}
		sort(pts.begin(), pts.end());
		for(auto &a : pts) {
			swap(a.first, a.second);
			for(int on = upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on) {
				if(coord[on].empty() || coord[on].back() != a.second) {
					coord[on].push_back(a.second);
				}
			}
		}
		for(int i = 0; i < fw.size(); i++) {
			fw[i].assign(coord[i].size() + 1, 0);
		}
	}
 
	void upd(T x, T y, T v) { // x -> inf y -> inf
		for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx) {
			for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy) {
				fw[xx][yy] += v;
			}
		}
	}
 
	T qry(T x, T y) { // 0 <- x, 0 <- y
		T ans = 0;
		for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx) {
			for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy) {
				ans += fw[xx][yy];
			}
		}
		return ans;
	}
 
	T qry(T x1, T y1, T x2, T y2) {
		return qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1);
	}
 
	void upd(T x1, T y1, T x2, T y2, T v) {
		upd(x1, y1, v);
		upd(x1, y2 + 1, -v);
		upd(x2 + 1, y1, -v);
		upd(x2 + 1, y2 + 1, v);
	}
private:
	vector<T> ord;
	vector<vector<T>> fw, coord;
};

inline int id(vector<int> &v, int val){
    return 1 + lower_bound(v.begin(), v.end(), val) - v.begin();
}


const int MAXX = 1e5 + 2;
int q[MAXX][5];
ll ans[MAXX];
vector<int> X, Y;

int n, m, k;
int main (){
	scanf("%d", &n);
    X.clear();
    Y.clear();
	for(int a=0;a<n;a++){
        int t;
        scanf("%d", &t);
        int x, y, xx, yy;
        scanf("%d%d", &x, &y);
        X.pb(x);
        Y.pb(y);
        q[a][0] = t;
        q[a][1] = x;
        q[a][2] = y;
        if(t == 2){
            scanf("%d%d", &xx, &yy);
            q[a][3] = xx;
            q[a][4] = yy;
            X.pb(xx);
            Y.pb(yy);
        }
	}
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    vector<pii> pts;
    for(int a=0;a<n;a++){
        int t = q[a][0];
        q[a][1] = id(X, q[a][1]);
        q[a][2] = id(Y, q[a][2]);
        pts.pb({q[a][1], q[a][2]});
        if(t == 2){
            q[a][3] = id(X, q[a][3]);
            q[a][4] = id(Y, q[a][4]);
            pts.pb({q[a][3], q[a][4]});
            pts.pb({q[a][1], q[a][4]+1});
            pts.pb({q[a][3]+1, q[a][2]});
            pts.pb({q[a][3]+1, q[a][4]+1});
        }
    }
    X.clear();
    Y.clear();
    Bit2D<int> bit(pts);
    for(int a=0;a<n;a++){
        int t = q[a][0];
        int x, y, xx, yy;
        x = q[a][1];
        y = q[a][2];
        if(t == 1){
            ans[a] = bit.qry(x, y);
        }
        else{
            xx = q[a][3];
            yy = q[a][4];
            bit.upd(x, y, xx, yy, 1);
        }
    }
    bit = Bit2D<int>(pts);
    for(int a=0;a<n;a++){
        int t = q[a][0];
        int x, y, xx, yy;
        x = q[a][1];
        y = q[a][2];
        if(t == 1){
            bit.upd(x, y, 1);
        }
        else{
            xx = q[a][3];
            yy = q[a][4];
            //upd2R(root, 0, szx-1, x, xx, y, yy);
            ans[a] = bit.qry(x, y, xx, yy);
        }
        ans[a] += (a > 0 ? ans[a-1] : 0);
        printf("%lld\n", ans[a]);
    }
}
