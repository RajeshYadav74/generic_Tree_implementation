#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode
{   public:

    int data;
    vector<TreeNode*> children;

    TreeNode(int data)
    {  
        this->data=data;

    }
    ~TreeNode()
    {
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
    }
};
void preOrder(TreeNode* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
}

void deleteTree(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    for(int i=0;i<root->children.size();i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

void postOrder(TreeNode* root)
{
     for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children[i]);
    }
    cout<<root->data<<" ";

}

void printAtLevelK(TreeNode* root,int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
        return ;
    }
    for(int i=0;i<root->children.size();i++)
    {
        printAtLevelK(root->children[i],k-1);
    }

}

int height(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int mx=0;
    for(int i=0;i<root->children.size();i++)
    {
        int maxHeight=height(root->children[i]);
        if(maxHeight>mx)
        {
            mx=maxHeight;
        }
    }
    return mx+1;
}

int countLeafNode(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
       ans+= countLeafNode(root->children[i]);
    }
    return ans;
}

int countNode(TreeNode* root)
{
    if(root==NULL)
    {
        return 0 ;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNode(root->children[i]);
    }
    return ans+1;
}

TreeNode* takeInputLevelWise()
{
    cout<<"Enter root data: ";
    int data;
    cin>>data;
    TreeNode* root=new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode* front=q.front();
        q.pop();
        cout<<"Enter no. of children of "<<front->data<<" ";
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cout<<"Enter "<<i<<" child of "<<front->data<<" "<<endl;
            int childData;
            cin>>childData;
            TreeNode* childNode=new TreeNode(childData);
            q.push(childNode);
            front->children.push_back(childNode);
        }
        //cout<<endl;
    }
    return root;
}

void printLevelWise(TreeNode* root)
{
    //cout<<root->data<<":";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* front=q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}

TreeNode* takeInput()
{
    cout<<"Enter root data: ";
    int data;
    cin>>data;
    TreeNode* root=new TreeNode(data);
    cout<<"Enter no. of children ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode* child=takeInput();
        root->children.push_back(child);
    }
    return root;
}
void print(TreeNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }
}
int main()
{
    TreeNode* root=takeInputLevelWise();
    printLevelWise(root);
    cout<<endl;
    cout<<"Total Node: "<<countNode(root)<<endl;
    cout<<"Leaf Node is: "<<countLeafNode(root);
    cout<<endl<<"Height is: "<<height(root)<<endl;
    cout<<"Nodes are at a level of 1: ";
    printAtLevelK(root,1);
    cout<<endl;
    cout<<"pre order trversal: ";
    preOrder(root);
    cout<<endl;
    cout<<"post order trversal: ";
    postOrder(root);

    delete root;
    
    
    return 0;
    
}
