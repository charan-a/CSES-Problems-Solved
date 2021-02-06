#include<bits/stdc++.h>

#define ll long long;
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fr(a,b,i) for(int i = a; i < b; i++)
#define f0(a,i) for(int i = 0; i < a; i++)
#define fe(a,b,i) for(int i = a; i <= b ; i++)
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
#define pr(x) cout<< x <<destl
#define vii vector<int,int>
#define sz(x) (int)(x).size()
#define pr_mat(x) for(auto &i : x){ for( &j : i){ cout<<j<<" "; } cout<<endl;}cout<<endl;
#define pr_arr(x) for(auto &i : x){ cout <<i<<" "; } cout<<endl;
using namespace std;

const int MOD = 1000000007;

char mat[1001][1001];
bool vis[1001][1001];
int path[1001][1001];
int mons[1001][1001];
int n,m,x,y;
int row[] = {1,0,-1,0};
int col[] = {0,-1,0,1};
char dir[] = {'D','L','U','R'};
queue<pii> que;
pii temp;
int lvl,l, ans,test;
bool flag = false;
pii start, dest;

void bfs(int x,int y){
    lvl = 0; l = 0;
    pii p = mp(x,y);
    que.push(p);
    vis[x][y] = true;
    while(!que.empty()){
        if(l <= 0){ l = sz(que);  lvl++;}
        l--;
        temp = que.front(); que.pop();
        f0(4,i){
            pii pp = mp(temp.f + row[i], temp.s + col[i]);
            x = pp.f; y = pp.s;
            if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#' || vis[x][y] || mons[x][y] <= lvl)
                continue;
            else if(x == 0 || x == n-1 || y == 0 || y == m-1){
                vis[x][y] = true;
                path[x][y] = i; ans = lvl;flag = true; dest = mp(x,y);
                return;
            }
            vis[x][y] = true;
            path[x][y] = i;
            que.push(pp);
        }
    }
}

void bfsm(){
    lvl = 0; l = 0;
    while(!que.empty()){
        if(l <= 0){ l = sz(que);  lvl++;} 
        l--;
        temp = que.front(); que.pop();
        f0(4,i){
            pii pp = mp(temp.f + row[i], temp.s + col[i]);
            x = pp.f; y = pp.s;
            if(x < 0 || x >= n || y < 0 || y >= m || mat[x][y] == '#'|| mat[x][y] == 'M'|| vis[x][y])
                continue;
            
            vis[x][y] = true;
            mons[x][y] = min(lvl,mons[x][y]) ;
            que.push(pp);
        }
    }
}

int main(){
    fast_io;
    int val;
    cin>>n>>m;
    f0(n+1,i){
        fill_n(mons[i],m+1,INT_MAX);
    }
    f0(n,i)
        f0(m,j)
            cin>>mat[i][j];
    f0(n,i)
        f0(m,j){
            if(mat[i][j] == 'A'){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    start = dest = mp(i,j);
                    flag = true;
                }else{
                    start = mp(i,j);
                }
            }else if(mat[i][j] == 'M'){
                mons[i][j] = 0;
                que.push(mp(i,j));
            }
                
        }
    bfsm();
    que = queue<pii>();
    f0(n+1,i) f0(m+1,j) vis[i][j] = false;
    bfs(start.f,start.s);
    if(flag){
        cout<<"YES"<<endl;
        vi steps;
        while(start != dest){    
            val = path[dest.f][dest.s]; 
            steps.pb(val);
            dest = mp(dest.f - row[val], dest.s - col[val]);
        }
        reverse(all(steps));
        cout<<sz(steps)<<endl;
        for(int z : steps)
            cout<<dir[z];
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    // fr(0,n,i){
    //     fr(0,m,j){
    //         test = (mons[i][j] == INT_MAX) ? 9 : mons[i][j];
    //         cout<<test<<"    ";
    //     }cout<<endl;
    // }
    
    return 0;
}
