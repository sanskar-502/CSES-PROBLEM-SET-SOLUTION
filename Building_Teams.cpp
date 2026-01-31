#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

#define len(x) int((x).size())
#define pb push_back

bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

/* Result and Observations
friend --> 1  -> 2  -> 3

*/

bool dfs(int node, vector<bool> & visited, unordered_map<int, vector<int>> & adj, vector<int> & ans, int prev){

    visited[node]= true;

    for(auto & neigh : adj[node] ){
        if(!visited[neigh]){
            ans[neigh]= (prev == 1 ? 2 : 1);
            if(!dfs(neigh, visited, adj, ans, ans[neigh])) return false;;
        }else{
            if( ans[node] != -1 && ans[node]== ans[neigh]){
                return false;
            }
        }
    }

    return true;
}

void sanskar_502() {
    int n,m;
    cin>>n>>m;

    unordered_map<int, vector<int>> adj;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // for(int i=1; i<=n ;i++){
    //     cout<<i<<sp<<"-->";
    //     for(auto & neigh : adj[i]){
    //         cout<<neigh<<sp<<",";
    //     }
    //     cout<<endl;
    // }


    vector<bool> visited(n+1, false);
    vector<int> ans(n+1, -1);

    for(int i=1; i<=n ; i++){
        if (!visited[i]) {
            ans[i] = 1;

        if (!dfs(i, visited, adj, ans, 1)) {
            cout << "IMPOSSIBLE" << nl;
            return;
        }
    }
}
        


    for(int i=1; i<ans.size(); i++){
        cout<<ans[i]<<sp;
    }

    cout<<nl;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        sanskar_502();
}

/*
    Golden Rules:
    Solutions are simple.
    Proofs are simple.
    Implementations are simple.
*/