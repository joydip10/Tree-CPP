#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector <int> segtree;
int arr[100001];
int cnt[100001];
int str[100001];

void init(int node,int b, int e)
{
    if(b==e)
    {
        segtree[node]=(arr[b]);
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,right);
    segtree[node]=max(segtree[left],segtree[right]);;
}
int query(int node, int b,int e, int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    else if(i>=b && j<=e)
    {
        return segtree[node];
    }
    int left=2*node;
    int right = left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return max(p1,p2);
}
int main()
{
    memset(arr,0,sizeof(arr));
    memset(cnt,0,sizeof(cnt));
    memset(str,-1,sizeof(arr));
    int s=0;

}
