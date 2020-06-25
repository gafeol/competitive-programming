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

int n, m, k;

const long double pi = acos(-1);
typedef long double cood; cood eps = 1e-7; // risky: XXX, untested: TODO
struct pnt { 
	cood x, y, z;
	pnt () : x(0), y(0), z(0) {} pnt (cood a, cood b, cood c) : x(a), y(b), z(c) {}
	inline pnt operator - (pnt o) { return pnt(x - o.x, y - o.y, z - o.z); }
	inline pnt operator + (pnt o) { return pnt(x + o.x, y + o.y, z + o.z); }
	inline pnt operator * (cood o) { return pnt(x*o, y*o, z*o); }
	inline pnt operator / (cood o) { return pnt(x/o, y/o, z/o); }
	inline cood operator * (pnt o) { return x*o.x + y*o.y + z*o.z; } // inner: |this||o|*cos(ang)
	inline pnt operator ^ (pnt o) { return pnt(y*o.z - z*o.y, z*o.x - x*o.z, x*o.y - y*o.x); } // cross: oriented normal to the plane containing the two vectors, has norm |this||o|*sin(ang)
	inline cood operator () (pnt a, pnt b) { return (*this)*(a^b); } // mixed: positive on the right-hand rule (thumb=this,index=a,mid=b)

	inline cood inner (pnt a, pnt b) { return (a-(*this))*(b-(*this)); }
	inline pnt cross (pnt a, pnt b) { return (a-(*this))^(b-(*this)); } // its norm is twice area of triangle
	inline cood mixed (pnt a, pnt b, pnt c) { return (a-(*this))(b-(*this),c-(*this)); } // 6 times the oriented area of thetahedra

	inline cood sq (pnt o = pnt()) { return inner(o,o); }
	inline long double nr (pnt o = pnt()) { return sqrt(sq(o)); }
	inline pnt operator ~ () { return (*this)/nr(); }

	inline bool in_seg (pnt a, pnt b) { return cross(a,b).sq() <= eps && inner(a,b) <= eps; } // tips included
	inline bool in_tri (pnt a, pnt b, pnt c) { return abs(mixed(a,b,c)) <= eps && cross(a,b)*cross(b,c) >= -eps && cross(a,b)*cross(c,a) >= -eps; } // border included$

	inline pnt proj (pnt a, pnt b) { return a + (b-a)*a.inner(b,(*this))/a.sq(b); }
	inline pnt proj (pnt a, pnt b, pnt c) { pnt n = a.cross(b,c); return (*this) - n*(n*((*this)-a))/n.sq(); }

	inline long double dist2_lin (pnt a, pnt b) { return cross(a,b).sq()/a.sq(b); }
	inline long double dist2_seg (pnt a, pnt b) { return a.inner(b,(*this))*b.inner(a,(*this)) <= eps ? min(sq(a),sq(b)) : dist2_lin(a,b); }
	inline long double dist_pln (pnt a, pnt b, pnt c) { return abs((~a.cross(b,c))*((*this)-a)); }
	inline long double dist2_tri (pnt a, pnt b, pnt c) { pnt p = proj(a,b,c); return p.in_tri(a,b,c) ? sq(p) : min({ dist2_seg(a,b), dist2_seg(b,c), dist2_seg(c,a) }); }
};
inline cood area (pnt a, pnt b, pnt c) { return abs(a.cross(b,c).nr()) / 2; }
inline cood vol (pnt a, pnt b, pnt c, pnt d) { return abs(a.mixed(b,c,d)) / 6; } // thetahedra
pnt inter_lin_pln (pnt s, pnt t, pnt a, pnt b, pnt c) { pnt n = a.cross(b,c); return s + (t-s)*(n*(a-s))/(n*(t-s)); } //$


int main (){
    for_tests(t, tt){
        n = 4;
        pnt s[2][5];
        for(int i=0;i<2;i++){
            for(int a=0;a<n;a++){
                ll x, y, z;
                scanf("%lld%lld%lld", &x, &y, &z);
                s[i][a] = {(long double)x,(long double)y,(long double)z};
            }
        }
        long double res = DBL_MAX;
        for(int v=0;v<4;v++){
            for(int a=0;a<4;a++){
                for(int b=a+1;b<4;b++){
                    for(int c=b+1;c<4;c++){
                        res = min(res, sqrt(s[0][v].dist2_tri(s[1][a], s[1][b], s[1][c])));
                        res = min(res, sqrt(s[1][v].dist2_tri(s[0][a], s[0][b], s[0][c])));
                    }
                }
            }
        }

        for(int i=0;i<2;i++){
            for(int a=0;a<4;a++){
                for(int b=a+1;b<4;b++){
                    for(int oa=0;oa<4;oa++){
                        for(int ob=oa+1;ob<4;ob++){
                            for(int oc=ob+1;oc<4;oc++){
                                // dist seg a-b no triang i pra triang oa, ob, oc no 1-i
                                pnt vec = s[i][b] - s[i][a];
                                long double l = 0, r = 1;
                                while(r - l > eps){
                                    long double lm = l + (r-l)/3.; 
                                    pnt vl = s[i][a] + (vec*lm);
                                    long double dl = sqrt(vl.dist2_tri(s[1-i][oa], s[1-i][ob], s[1-i][oc]));

                                    long double rm = r - (r-l)/3.;
                                    pnt vr = s[i][a] + (vec*rm);
                                    long double dr = sqrt(vr.dist2_tri(s[1-i][oa], s[1-i][ob], s[1-i][oc]));
                                    res = min(res, min(dl, dr));
                                    if(dl < dr)
                                        r = rm;
                                    else
                                        l = lm;
                                }
                                pnt v = s[i][a] + vec*((l+r)/2.);
                                res = min(res, sqrt(v.dist2_tri(s[1-i][oa], s[1-i][ob], s[1-i][oc])));
                            }
                        }
                    }
                }
            }
        }
        printf("%.6Lf\n", res);
    }
}

