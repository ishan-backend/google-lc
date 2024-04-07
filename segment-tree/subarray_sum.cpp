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
    st[node] = st[2*node] + st[2*node+1]; // subarray sum program
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
    return 0;
}
