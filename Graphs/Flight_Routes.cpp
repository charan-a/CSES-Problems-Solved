#include<bits/stdc++.h>

typedef long long ll;
#define vi vector<int>
#define vii vector<int,int>
#define vpii vector<pair<int,int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define f(a,b,i) for(int i = a; i < b; i++)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<endl
#define sz(x) (int)(x).size()
#define pr_mat2(x) for(auto &i : x){ for( &j : i){ cout<<j<<" "; } cout<<endl;}cout<<endl;
#define pr_mat(x,n,m) f(1,n+1,i){ f(1,m+1,j){ cout<<x[i][j] <<" "; } cout<<endl;}cout<<endl;
#define pr_arr(x) for(auto &i : x){ cout <<i<<" "; } cout<<endl;
#define pqll priority_queue<pll,vector<pll>,greater<pll>>
using namespace std;
const ll inf = 1e18+1;
const int MOD = 1000000007;
vector<pii> adj[200001];
priority_queue<ll> dis[200001];
pqll heap;

int main(){
    fast_io;
    ll n,m,k,a,b,c,u,v;
    ll d,d2,val,x;
    pii temp;
    cin>>n>>m>>k;
    f0(m,i){
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dis[1].push(0);dis[1].pop();
    heap.push({0,1});

    while(!heap.empty()){
        d = heap.top().ff; v = heap.top().ss; 
        heap.pop();
        if(dis[v].top() < d )   continue;
        for(auto x : adj[v]){
            u = x.ff; d2 = x.ss;
            val = d + d2;
            if(sz(dis[u]) < k || dis[u].top() > val){
                dis[u].push(val);
                heap.push({val,u});
                if(sz(dis[u]) > k ) dis[u].pop();
            }
        }
    }
    ll arr[k];
    f0(k,i){
        x = dis[n].top(); dis[n].pop();
        arr[i] = x;
    }
    sort(arr,arr+k);
    f0(k,i){
        cout<<arr[i]<<" ";
    }
    return 0;
}