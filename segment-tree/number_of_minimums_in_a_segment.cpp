#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2, MOD_MAX = 1e9+7; // 10^9+7
int arr[N];
pair<int, int> st[4*N];

// set the element at index i to v
// return the minimum and no of elements equal to minimum in the query(l, r) from l to r-1

void build(int node, int st, int en) { // node 1 of st ;st, en is [0, n-1] index of array arr
    if(st == en) {
        st[node].first = arr[st];
        st[node].second = 1;
        return;
    }
    
    // divide and conquer: recurse
    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    
    // backtracking: our logic
    if(st[2*node].first < st[2*node+1].first) {
        st[node].first = st[2*node].first; // smallest element
        st[node].second = st[2*node].second; // freq
    } else if(st[2*node+1].first < st[2*node].first) {
        st[node].first = st[2*node+1].first;
        st[node].second = st[2*node+1].second;
    } else { // when both children minimum is same
        st[node].first = st[2*node].first; // kisi ka bhi
        st[node].second = (st[2*node].second + st[2*node+1].second);
    }
}

// cases: complete and partial overlap
pair<int, int> query(int node, int st, int en, int l, int r) { // [l, r]  are of query and [st, en] is what is being taken care of by node
    if(st > r or en < l) {
        return {MOD_MAX, -1}; // out of range case: minimum and its freq
    }

    // l st en r - full overlap
    if(l <= st and r >= en) {
        return st[node];
    }

    // st l en r || l st r en - partial overlap
    int mid = (st+en)/2;
    pair<int, int> q1 = query(2*node, st, mid, l, r);
    pair<int, int> q2 = query(2*node+1, mid+1, en, l, r);
    if(q1.first < q2.first) {
        return q1;
    } else if(q2.first < q1.first) {
        return q2;
    } else {
        return {q1.first, q1.second + q2.second};
    }
}

void update(int node, int st, int en, int int idx, int val) {
      if(st == en) {
          arr[st] = val;
          st[st].first = val;
          st[st].second = 1;
          return;
      }

    // recurse
    int mid = (st+en)/2;
    if(idx <= mid)
        update(2*node, st, mid, idx, val);
    else
        update(2*node+1, mid+1, en, idx, val);
    
    // backtracking - update current node, similar to the logic of build()
    if(st[2*node].first < st[2*node+1].first) {
        st[node].first = st[2*node].first; // smallest element
        st[node].second = st[2*node].second; // freq
    } else if(st[2*node+1].first < st[2*node].first) {
        st[node].first = st[2*node+1].first;
        st[node].second = st[2*node+1].second;
    } else { // when both children minimum is same
        st[node].first = st[2*node].first; // kisi ka bhi
        st[node].second = (st[2*node].second + st[2*node+1].second);
    }
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
