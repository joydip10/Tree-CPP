#include<bits/stdc++.h>

using namespace std;

struct node
{
    bool endmask;
    node* next[27];
    node(){
        endmask=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
}* root;

void insert_node(char* str,int len)
{
    node* curr=root;
    for(int i=0;i<len;i++)
    {
        if(curr->next[str[i]-'a']==NULL)
        {
            curr->next[str[i]-'a']=new node();
        }
        curr=curr->next[str[i]-'a'];
    }
    curr->endmask=true;
}

void del(node* curr)
{
    for(int i =0;i<26;i++)
    {
        if(curr->next[i])
        {
            del(curr->next[i]);
        }
    }
    delete(curr);
}

bool search_node(char* str,int len)
{
    node* curr=root;
    for(int i=0;i<len;i++)
    {
        if(curr->next[str[i]-'a']==NULL)
        {
            return false;
        }
        else curr=curr->next[str[i]-'a'];
    }
    return curr->endmask;
}

int main()
{
    root=new node();
    cout<<"Enter number of words you want to enter into trie: ";
    int num;
    cin>>num;
    cout<<endl;
    for(int i=0;i<num;i++)
    {
        char ch[100];
        scanf("%s",ch);
        insert_node(ch,strlen(ch));
    }

    int query;
    cout<<"Input the number of queries you want to try: ";
    cin>>query;
    cout<<endl;
    for(int i =0;i<query;i++)
    {
        char ch[100];
        cin>>ch;
        cin.ignore();
        if(search_node(ch,strlen(ch)))
        {
            cout<<"Found"<<endl;
        }
        else cout<<"Not Found"<<endl;
    }
    del(root);
    return 0;

}

