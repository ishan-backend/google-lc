#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int arr[N], st[4*N];

void build(int node, int st, int en) { // node 1 of st ;st, en is [0, n-1] index of array arr
    if(st == en) {
        st[node] = arr[st];
        return;
    }
    
    // divide and conquer
    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    
    // our logic
    st[node] = max(st[2*node], st[2*node+1]); // maximum of this range
}

// cases: complete and partial overlap
int query(int node, int st, int en, int l, int r) { // [l, r]  are of query and [st, en] is what is being taken care of by node
    if(st > r or en < l) {
        return INT_MIN; // maximum of this range, out of bound so return minimum
    }

    // l st en r - full overlap
    if(l <= st and r >= en) {
        return st[node];
    }

    // st l en r || l st r en - partial overlap
    int mid = (st+en)/2;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
    return max(q1, q2);
}

void update(int node, int st, int en, int l, int r) {
  
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    build(1, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << st[i] << endl;
    }

    int q;
    cin>>q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1) {
            int l, r;
            cin>>l>>r;
            int ans = query(1, 0, n-1, l, r);
            cout << ans << endl;
        }
    }
    return 0;
}
