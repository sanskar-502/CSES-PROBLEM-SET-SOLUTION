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


*/





// bool detectionOFCycleUsingBfs(int node, vector<bool> &visited, vector<vector<int>> &adjList, vector<int> &parent, int &cycleStart, int &cycleEnd) {
//     visited[node] = true;
//     parent[node] = -1;
    
//     queue<int> q;
//     q.push(node);
    
//     while(!q.empty()){
//         int queueFront = q.front();
//         q.pop();
        
//         for(auto neig : adjList[queueFront]){
//             if(visited[neig] == true && neig != parent[queueFront]){
//                 cycleStart = queueFront; 
//                 cycleEnd = neig;
//                 return true;
//             }
//             else if(!visited[neig]){
//                 q.push(neig);
//                 visited[neig] = true;
//                 parent[neig] = queueFront;
//             }
//         }
//     }
//     return false;
// }

// void sanskar_502() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> adj(n + 1);
//     for(int i = 0; i < m; i++){
//         int u, v;
//         cin >> u >> v;
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }

//     vector<bool> visited(n + 1, false);
//     vector<int> parent(n + 1, 0); 
//     bool found = false;
//     vector<int> ans;
//     int cycleStart = -1, cycleEnd = -1;
    
//     for(int i = 1; i <= n; i++){
//         if(!visited[i]){
//             if (detectionOFCycleUsingBfs(i, visited, adj, parent, cycleStart, cycleEnd)) {
//                 found = true;
                
//                 vector<int> path1, path2;
//                 int a = cycleStart;
//                 int b = cycleEnd;

//                 while(a != -1){
//                     path1.push_back(a);
//                     a = parent[a];
//                 }
//                 while(b != -1){
//                     path2.push_back(b);
//                     b = parent[b];
//                 }

//                 reverse(path1.begin(), path1.end());
//                 reverse(path2.begin(), path2.end());

//                 int lca = -1;
//                 int sz = min(path1.size(), path2.size());
//                 for(int k = 0; k < sz; k++){
//                     if(path1[k] == path2[k]) lca = path1[k];
//                     else break;
//                 }

//                 int idx1 = -1, idx2 = -1;
       
//                 for(int k=0; k<path1.size(); k++) if(path1[k]==lca) idx1=k;
//                 for(int k=0; k<path2.size(); k++) if(path2[k]==lca) idx2=k;

//                 for(int k = path1.size()-1; k >= idx1; k--) ans.push_back(path1[k]);
//                 for(int k = idx2+1; k < path2.size(); k++) ans.push_back(path2[k]);

//                 ans.push_back(ans[0]); 
                
//                 break;
//             }
//         }
//     }

//     if(found){
//         cout << ans.size() << nl;
//         for(auto &ele : ans) cout << ele << sp;
//         cout << nl;
//     } else {
//         cout << "IMPOSSIBLE" << nl;
//     }
// }




vector<int> parent;
vector<bool> visited;
int cycleStart = -1, cycleEnd = -1;

bool dfs(int node, int par, vector<vector<int>> &adj) {
    visited[node] = true;
    parent[node] = par;

    for (auto neighbor : adj[node]) {

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj)) return true;
        } 
        else if(neighbor != par) {
            cycleStart= neighbor;
            cycleEnd=node;
            return true;
        }
    }
    return false;
}

void sanskar_502() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    cycleStart = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1, adj)) {
    
            vector<int> ans;
            ans.pb(cycleStart);
            
            for (int curr = cycleEnd; curr != cycleStart; curr = parent[curr]) {
                ans.pb(curr);
            }
            ans.pb(cycleStart);

            cout << ans.size() << nl;
            for (auto &ele : ans) cout << ele << sp;
            return;
        }
    }

    cout << "IMPOSSIBLE" << nl;
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