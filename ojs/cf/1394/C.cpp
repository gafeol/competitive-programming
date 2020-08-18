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

const int MAXN = 512345;

#define x fst
#define y snd

int n, m, k;
char s[MAXN];

int dist(pii p, pii pp){
    if(p.x > pp.x) swap(p, pp);
    printf("dist %d %d to %d %d is ", p.x, p.y, pp.x, pp.y);
    // p.x <= pp.x
    if(p.y <= pp.y){
        printf("%d\n", max(pp.x - p.x, pp.y - p.y)); 
        return max(pp.x - p.x, pp.y - p.y); 
    }
    else{
        printf("%d\n", pp.x - p.x + p.y - pp.y);
        return pp.x - p.x + p.y - pp.y;
    }
}

int main (){
    vector<pii> pts(8);
	scanf("%d", &n);
    vector<pii> inp(n);
	for(int a=0;a<n;a++){
        scanf(" %s", s);
        int sz = strlen(s);
        pii p = {0,0};
        for(int i=0;i<sz;i++){
            if(s[i] == 'B')
                p.fst++;
            else
                p.snd++;
        }
        inp[a]=p;
        if(a == 0){
            for(int i=0;i<8;i++){
                pts[i] = p;
            }
        }
        if(-pts[0].x + pts[0].y <= -p.x + p.y)
            pts[0] = p;
        if(pts[1].x - pts[1].y <= p.x - p.y)
            pts[1] = p;
        if(pts[2].x  + pts[2].y <= p.x + p.y)
            pts[2] = p;
        if(-pts[3].x - pts[3].y <= - p.x - p.y)
            pts[3] = p;
        if(pts[4].x < p.x)
            pts[4] = p;
        if(pts[5].y < p.y)
            pts[5] = p;
        if(pts[6].x > p.x)
            pts[6] = p;
        if(pts[7].y > p.y)
            pts[7] = p;
	}
    int mxDist = 0;
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
           mxDist = max(mxDist, dist(pts[i], pts[j]));
        }
    }
    printf("%d\n", (mxDist+1)/2);
    int nb, nn;
    for(int i=0;i<8;i++){
        for(int j=i+1;j<8;j++){
            if(dist(pts[i], pts[j]) == mxDist){
                nb = (pts[i].x + pts[j].x+1)/2;
                nn = (pts[i].y + pts[j].y+1)/2;
            }
        }
    }
    fim:
    mxDist = 0;
    printf("nb %d nn %d\n", nb, nn);
    for(int a=0;a<n;a++){
        mxDist = max(mxDist, dist({nb, nn}, inp[a]));
    }
    printf("%d\n", mxDist);
    while(nb--)
        printf("B");
    while(nn--)
        printf("N");
    puts("");
    return 0;
}

