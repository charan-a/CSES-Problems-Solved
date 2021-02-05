#include<bits/stdc++.h>
#define ll long long;
#define vi vector<int>
#define pii pair<int, int>v
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define f(a,b,i) for(int i = a; i < b; i++)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<endl
#define vii vector<int,int>
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1000000007;
int vis[100001];
vector<int> grp[100001];
int ch;
void dfs(int x){
    vis[x] = 1;
    f0(sz(grp[x]),i){
        ch = grp[x][i];
        if(vis[ch] == 0)
            dfs(ch);
    }
}

int main() {
    fast_io;
    int n,m,a,b,cnt=0;
    vi cc;
    // memset()
    cin>>n>>m;
    f0(m,i){
        cin>>a>>b;
        grp[a].pb(b);
        grp[b].pb(a);
    }
    f(1,n+1,i){
        if(vis[i] == 0){
            cc.pb(i);
            cnt++;
            dfs(i);
        }
    }
    pr(cnt-1);
    f0(sz(cc)-1,j){
        cout<<cc[j]<<" "<<cc[j+1]<<endl; 
    }
   
    return 0;
}