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
#define debug(args...) //fprintf(stderr,args)
#else
#define debug(args...)
#endif //ONLINE_JUDGE
#define fore(x, i, j) for(int x=i;x<j;x++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define IOS() ios::sync_with_stdio(0),cin.tie(0)

const int MAXN = 19;
const int BIT = (1<<18);

const double EPS = 1e-8;

// simplex - el vasito
vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;

void pivot(int x,int y){
    swap(X[y],Y[x]);
    b[x]/=A[x][y];
    fore(i,0,m)if(i!=y)A[x][i]/=A[x][y];
    A[x][y]=1/A[x][y];
    fore(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
        b[i]-=A[i][y]*b[x];
        fore(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
        A[i][y]=-A[i][y]*A[x][y];
    }
    z+=c[y]*b[x];
    fore(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
    c[y]=-c[y]*A[x][y];
}
pair<double,vector<double> > simplex( // maximize c^T x s.t. Ax<=b, x>=0
        vector<vector<double> > _A, vector<double> _b, vector<double> _c){
    // returns pair (maximum value, solution vector)
    A=_A;b=_b;c=_c;
    n=b.size();m=c.size();z=0.;
    X=vector<int>(m);Y=vector<int>(n);
    fore(i,0,m)X[i]=i;
    fore(i,0,n)Y[i]=i+m;
    while(1){
        int x=-1,y=-1;
        double mn=-EPS;
        fore(i,0,n)if(b[i]<mn)mn=b[i],x=i;
        if(x<0)break;
        fore(i,0,m)if(A[x][i]<-EPS){y=i;break;}
        assert(y>=0); // no solution to Ax<=b
        pivot(x,y);
    }
    while(1){
        double mx=EPS;
        int x=-1,y=-1;
        fore(i,0,m)if(c[i]>mx)mx=c[i],y=i;
        if(y<0)break;
        double mn=1e200;
        fore(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
        assert(x>=0); // c^T x is unbounded
        pivot(x,y);
    }
    vector<double> r(m);
    fore(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
    return {z,r};
}

int main (){
    scanf("%d%d", &n, &m); 
    c.resize(n, 0);
    for(int a=0;a<m;a++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--;v--;
        c[u] -= w;
        c[v] += w;

        vector<double> lin(n, 0);
        lin[v] = 1;
        lin[u] = -1;
        A.pb(lin);
        b.pb(-1);
    }
    auto sol = simplex(A, b, c);
    //printf("sol val %.5f\n", sol.fst);

    for(double x: sol.snd){
        printf("%d ", (int)round(x));
    }
    puts("");
}

