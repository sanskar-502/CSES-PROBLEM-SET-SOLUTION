#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

#define len(x) int((x).size())
#define pb push_back
#define ll long long

bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }


int getMid(int s, int e) { return s + (e - s) / 2; }

ll constructSTUtil(ll arr[], int ss, int se, ll *st, int si) {
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, 2*si+1) + constructSTUtil(arr, mid+1, se, st, 2*si+2);

    return st[si];
}

ll* constructST(ll arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

ll getSumUtil(ll *st, int ss, int se, int qs, int qe, int si) {
    if (qs <= ss && qe >= se) return st[si]; 
    if (se < qs || ss > qe) return 0;  
    int mid = getMid(ss, se);

    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

ll getsum(ll *st, int n, int l, int r) {
    return getSumUtil(st, 0, n-1, l, r, 0);
}

void updateValueUtil(ll *st, int ss, int se, int i, ll diff, int si) {
    if (i < ss || i > se) return;
    st[si] += diff;
    if (ss != se) {
        int mid = getMid(ss, se);
        
        updateValueUtil(st, ss, mid, i, diff, 2*si+1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si+2);
    }
}

void updateValue(ll *arr, ll *st, int n, int index, int new_val) {
    ll diff = new_val - arr[index];
    arr[index] = new_val;
    updateValueUtil(st, 0, n-1, index, diff, 0);
}


void sanskar_502() {
    int n, q;
    cin >> n >> q;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    ll *st = constructST(arr, n);
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >>x >> y;
        x--, y--;
            cout << getsum(st, n, x, y) << nl;
    }
    
    delete[] st;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        sanskar_502();
}
