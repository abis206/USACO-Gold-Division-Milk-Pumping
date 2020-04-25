#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define S second
#define F first
#define MEM(i, j) memset(i, j, sizeof(i))
using namespace std;
const int MAXN = 100005;
typedef long long ll;
int n, m;
vector<pair<int, pii>> adj[1005];
priority_queue< pii, vector<pii>, greater<pii>> pq;
int dis[1005];
int dijkstra(int rate){
    pq.push({0, 1});
    while(!pq.empty()){
        int ver = pq.top().S;
        int val = pq.top().F;
        pq.pop();
        if(dis[ver] != -1 && dis[ver] <= val)
            continue;
        dis[ver] = val;
        if(ver == n){
            return val;
        }
        for(auto x : adj[ver]){
            int node = x.F;
            int c = x.S.F;
            int f = x.S.S;
            if(f < rate)
                continue;
            if(dis[node] == -1)
                pq.push({val + c, node});
        }
    }
    return -1;
}
int main(){
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    cin>>n>>m;
    vector<int> vec;
    for(int i=0;i<m;i++){
        int x, y, w, z;
        cin>>x>>y>>w>>z;
        vec.pb(z);
        adj[x].pb({y, {w, z}});
        adj[y].pb({x, {w, z}});
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for(auto f : vec){
        while(!pq.empty())
            pq.pop();
        MEM(dis, -1);
        int num = dijkstra(f);
        if(num == -1)
            continue;
        ans = max(ans, 1LL * 1000000 * f / num);
    }
    cout<<ans;
    return 0;
}
