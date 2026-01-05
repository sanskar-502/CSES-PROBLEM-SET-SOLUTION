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
    used the concept of dp and tree
    here tree-rooting is used 



    dist[v]  += dist[v] + dist[c]  + subtree[c];

*/
ll maxi= LLONG_MIN;

void re_rooting(int node, int parent, vector<ll> &dist, vector<ll> &subtree_sum, vector<vector<int>> &adj, vector<ll> &ans){
    ans[node] = dist[node];
    maxi= max(maxi, dist[node]);

    for(auto& neigh : adj[node]){
        if(neigh != parent){
            subtree_sum[node] -= subtree_sum[neigh];
            dist[node] -= (dist[neigh] + subtree_sum[neigh]);

            subtree_sum[neigh] += subtree_sum[node];
            dist[neigh] += (dist[node] + subtree_sum[node]);

            re_rooting(neigh, node, dist, subtree_sum, adj,ans);

            subtree_sum[neigh] -= subtree_sum[node];
            dist[neigh] -= (dist[node] + subtree_sum[node]);

            subtree_sum[node] += subtree_sum[neigh];
            dist[node] += (dist[neigh] + subtree_sum[neigh]);
        }
    }
}

void preCompute(int node, int parent, vector<ll> &dist, vector<ll> &subtree_sum, vector<vector<int>> &adj){
    subtree_sum[node]=1;
    dist[node]=0;

    for(auto &neigh : adj[node]){
        if(neigh != parent){
            preCompute(neigh, node, dist, subtree_sum, adj);
            subtree_sum[node] += subtree_sum[neigh];
            dist[node] +=  (dist[neigh] + subtree_sum[neigh]);
        }
    }
}

void sanskar_502() {
    ll n;
    cin>>n;

    vector<vector<int>> adj(n+1);

    for(ll i=0; i< n-1; i++){
        ll u; ll v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dist(n+1, 0);
    vector<ll> subtree_sum(n+1, 0);
    vector<ll> ans(n + 1, 0);

    preCompute(1, -1, dist, subtree_sum, adj);

    re_rooting(1, -1, dist, subtree_sum, adj, ans);

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<sp;
    }
    cout<<endl;
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