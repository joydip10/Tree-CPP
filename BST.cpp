#include<bits//stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;
};
tree* newNode(int value)
{
    tree *root= new tree();
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    return root;
}
tree* insert_newNode(tree* root,int value)
{
    if(root==NULL)
    {
        return newNode(value);
    }
    else if(root->data<value)
    {
        root->right=insert_newNode(root->right,value);
    }
    else if(root->data>value)
    {
        root->left=insert_newNode(root->left,value);
    }
    return root;
}
map<int,tree*> level;
int i =0;
tree* search_node(tree* root,int key)
{
    level[i]=root;

    if(root==NULL || root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        i++;
        search_node(root->left,key);
    }
    else if(root->data<key)
    {
        i++;
        search_node(root->right,key);
    }
}
tree* minimum(tree* node)
{
    tree* current = node;
    while(current && current->left!=NULL)
    {
        current=minimum(current->left);
    }
    return current;
}
tree* delete_node(tree* root, int value)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data>value)
    {
        root->left=delete_node(root->left,value);
    }
    else if(root->data<value)
    {
        root->right=delete_node(root->right,value);
    }
    else
    {
        if(root->right==NULL)
        {
            tree* temp = new tree();
            temp = root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            tree* temp = new tree();
            temp = root->right;
            delete(root);
            return temp;
        }
        tree* node= minimum(root->right);
        root->data=node->data;
        root->right=delete_node(root->right,node->data);

    }
    return root;
}
inorder(tree* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    tree* root= new tree();
    root=NULL;
    root=insert_newNode(root,50);
    insert_newNode(root,30);
    insert_newNode(root,20);
    insert_newNode(root,40);
    insert_newNode(root,70);
    insert_newNode(root,60);
    insert_newNode(root,80);
    inorder(root);
    cout<<endl;
    tree* findnode= search_node(root,40);
    cout<<findnode->data<<endl;
    cout<<i<<endl;
    cout<<level[i]->data<<endl;
    cout<<minimum(root)->data<<endl;
    root= delete_node(root,50);
    inorder(root);
    return 0;
}
