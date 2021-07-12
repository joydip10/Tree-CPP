#include<bits//stdc++.h>
#define MAX 100001
using namespace std;
int arr[MAX];
int tree[MAX*3];
int treemax[MAX*3];
void initmax(int node,int b,int e)
{
    if(b==e)
    {
        treemax[node]=arr[b];
        return;
    }
    int left=2*node;
    int right = left+1;
    int mid =(b+e)/2;
    initmax(left,b,mid);
    initmax(right,mid+1,e);
    treemax[node]=max(treemax[left],treemax[right]);

}
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int query(int node , int b,int e,int i,int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(i<=b && j>=e)
    {
        return tree[node];
    }
    int left= node*2;
    int right = left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
int maxquery(int node,int b,int e,int i,int j)
{
    if(i > e || j < b)
    {
        return -1000000000;
    }
    if(b >= i && e <= j)
    {
        return treemax[node];
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=maxquery(left,b,mid,i,j);
    int p2=maxquery(right,mid+1,e,i,j);
    return max(p1,p2);
}
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    arr[0]=0;
    tree[0]=0;
    treemax[0]=0;
    int length;
    cout<<"Enter the array length: ";
    cin>>length;
    for(int i = 1;i<=length;i++)
    {
        cin>>arr[i];
    }
    init(1,1,length);
    initmax(1,1,length);
    int range_min,range_max;
    cout<<"Enter the range_min and range_max: ";
    cin>>range_min>>range_max;
    cout<<"Sum of all of the elements in the given range: ";
    cout<<query(1,1,7,range_min,range_max)<<endl;
    cout<<"Maximum element of all elements in the given range: ";
    cout<<maxquery(1,1,7,range_min,range_max)<<endl;
    return 0;
}
