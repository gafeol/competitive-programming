#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAXN 112345
#define MAXN2 4123456
#define MOD 1000000007
#define f first
#define s second
#define mt make_tuple
#define int long long
#define ll long long
#define pii pair<long long, long long>
#define INF LLONG_MAX

using coord=int;
#define EPS 0

namespace basic {
    #define X real()
    #define Y imag()
    const long double PI = 4 * atan(1);

    int signal(coord x) { return (x > EPS) - (x < -EPS); }
    coord sq(coord x) { return x * x; }

    using point = complex<coord>;
    coord dot(point a, point b) { return (conj(a) * b).X; }
    coord cross(point a, point b) { return (conj(a) * b).Y; }
    point rotate90(point p) { return p * point(0, 1); }
    point projection(point p, point d) { return d * (dot(p, d) / norm(d)); }
    point normalized(point p) { return p / abs(p); }

    struct line {
        point p; coord c;
        line() {}
        line(point a, point b): p(rotate90(b - a)), c(dot(p, a)) {}
        line(point p, coord c): p(p), c(c) {}
    };
    line perpendicular(line l) { return {rotate90(l.p), l.c}; }
    line parallel(line l, point v) { return {l.p, dot(l.p, v)}; }
    bool contains(line l, point v) { return signal(l.c - dot(l.p, v)) == 0; }
    bool intersects(line l1, line l2) { return signal(cross(l1.p, l2.p)); }
    point intersection(line l1, line l2) {
        if (!intersects(l1, l2)) throw 1;
        point p(cross({l1.c, l1.p.Y}, {l2.c, l2.p.Y}), cross({l1.p.X, l1.c}, {l2.p.X, l2.c}));
        return p / cross(l1.p, l2.p);
    }
    coord distance_sq(line l, point v) { return sq(l.c - dot(l.p, v)) / norm(l.p); }

    struct segment { point a, b; };
    bool contains(segment s, point p) {
        return signal(cross(p - s.a, s.b - s.a)) == 0 && signal(dot(p - s.a, p - s.b)) <= 0;
    }
    bool intersects(segment s1, segment s2) {
        if (contains(s1, s2.a) || contains(s1, s2.b) || contains(s2, s1.a) || contains(s2, s1.b))
            return true;
        auto side = [](point p, segment s) { return signal(cross(s.b - s.a, p - s.a)); };
        return side(s2.a, s1) * side(s2.b, s1) == -1 && side(s1.a, s2) * side(s1.b, s2) == -1;
    }
    coord distance_sq(segment s, point p) {
        if (signal(dot(s.b - s.a, p - s.a)) * signal(dot(s.a - s.b, p - s.b)) >= 0)
            return distance_sq(line(s.a, s.b), p);
        return min(norm(p - s.a), norm(p - s.b));
    }


};
using namespace basic;

vector<point> convex_hull(vector<point> p) {
    if (p.size() == 1) return p;
    auto cmp = [](point a, point b) { return make_pair(a.X, a.Y) < make_pair(b.X, b.Y); };
    sort(p.begin(), p.end(), cmp);
    point l = p[0], r = p.back();
    vector<point> up({l}), down({l});
    auto side = [](point a, point b, point c) { return signal(cross(b - a, c - a)); };
    for (int i = 1; i < (int)p.size(); i++) {
        // to include collinear points, change > to >=, >= to >, < to <= and <= to <
        if (i == (int)p.size() - 1 || side(l, r, p[i]) > 0) {
            while (up.size() >= 2 && side(up[(int)up.size() - 2], up.back(), p[i]) >= 0)
                up.pop_back();
            up.push_back(p[i]);
        }
        if (i == (int)p.size() - 1 || side(l, r, p[i]) < 0) {
            while (down.size() >= 2 && side(down[(int)down.size() - 2], down.back(), p[i]) <= 0)
                down.pop_back();
            down.push_back(p[i]);
        }
    }
    vector<point> h;
    for (int i = 0; i < (int)up.size(); i++)
        h.push_back(up[i]);
    for (int i = (int)down.size() - 2; i > 0; i--)
        h.push_back(down[i]);
    return h;
}

int area2(vector<point> &p) {
    int ans=0;
    for(int i=0;i<p.size();i++){
        ans+=p[i].X*p[(i+1)%p.size()].Y-p[i].Y*p[(i+1)%p.size()].X;
    }
    return abs(ans);
}


//se if point q is contained in "polygon" p. 
//p might be a point or segment :(
int contains(vector<point> &p, point q){
    //for(auto x:p)cout<<x.X<<" "<<x.Y<<"  ";
    //cout<<endl;
    //cout<<q.X<<" "<<q.Y<<endl;
    if(p.size()==1)return p[0]==q;
    if(p.size()==2){
        segment s=segment{p[0],p[1]};
        return contains(s,q);
    }
    for(int i=0;i<p.size();i++){
        if(cross(p[(i+1)%p.size()]-p[i],q-p[i])>0)return 0;
    }
    return 1;
}

int aa,ab,ac,ba,bb,bc;

int dist2(tuple<int,int,int> a,tuple<int,int,int> b){
    tie(aa,ab,ac)=a;
    tie(ba,bb,bc)=b;
    return sq(aa-ba)+sq(ab-bb)+sq(ac-bc);
}

int m;
int pai[MAXN],peso[MAXN];

int find(int x){
    return pai[x]=(x==pai[x]?x:find(pai[x]));
}

void join(int x,int y){
    if((x=find(x))==(y=find(y)))return;
    if(peso[x]<peso[y])swap(x,y);
    peso[x]+=peso[y];pai[y]=x;
}

void init(){
    for(int i=0;i<m;i++)peso[pai[i]=i]=1;
}

int cost[11234];
bool ext[11234];

map<int,vector<point>> mm;
map<int,vector<point>> mc;
//two times the area of the corresponding polygon
map<int,int> mmm;
int r;
    vector<tuple<int,int,int>> pillars;

int dij(int from){
    set<pair<int, int>> q;
    vector<ll> dis(pillars.size(), INF);
    dis[from] = 0;
    q.insert({0, from});
    while(!q.empty()){
        auto [du, u] = *q.begin();
        q.erase(q.begin());
        auto [x, y, z] = pillars[u];
        for(int v=0;v<pillars.size();v++){
            auto [vx, vy, vz] = pillars[v];
            int d2 = dist2(pillars[u], pillars[v]);
            if(z >= vz && d2 <= r*r && dis[v] > dis[u] + cost[v]){
                if(dis[v] != INF)
                    q.erase({dis[v], v});
                dis[v] = dis[u] + cost[v];
                q.insert({dis[v], v});
            }
        }
    }
    int ans = INF;
    auto [ix, iy, iz] = pillars[from];
    for(int u=0;u<pillars.size();u++){
        if(ext[u]){
            auto [ex, ey, ez] = pillars[u];
            if(dis[u] == INF) continue;
            ans = min(ans, dis[u] + abs(iz - ez)*2ll);
        }
    }
    return ans;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<setprecision(8)<<fixed;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        pillars.pb(mt(x,y,z));
    }
    cin>>m;
    vector<pair<tuple<int,int,int>,int>> dogs;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        x--;
        int h;
        cin>>h;
        dogs.pb(mp(pillars[x],h));
    }
    init();
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j)continue;
            if(dist2(dogs[i].first,dogs[j].first)<=sq(dogs[i].second)){
                join(i,j);
            }
        }
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        tie(x,y,z)=dogs[i].f;
        mm[find(i)].pb(point(x,y));
    }
    for(auto x:mm){
        mc[x.f]=convex_hull(x.s);
    }
    for(auto x:mc){
        mmm[x.f]=area2(x.s);
        //cout<<x.f+1<<" "<<mmm[x.f]<<endl;
    }
    for(int i=0;i<n;i++){
        int x,y,z;
        tie(x,y,z)=pillars[i];
        point p=point(x,y);
        for(auto xx:mc){
            //cout<<i+1<<" "<<contains(xx.s,p)<<endl;
            if(contains(xx.s,p)){
                cost[i]=mmm[xx.f];
                break;
            }
        }
    }

    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        ext[x-1]=1;
    }

    int ini;
    cin>>ini;
    ini--;
    cin>>r;
    int a;
    cin>>a;
    int val=dij(ini);
    //cout<<val<<endl;
    if(2*a>=val)cout<<0.5*(2*a-val)<<endl;
    else cout<<-1.<<endl;

    
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 

