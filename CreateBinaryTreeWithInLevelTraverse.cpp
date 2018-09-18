#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d):data(d),left(NULL),right(NULL){};
};

Node *_CBT_In_Level(const vector<int> &levelarr, \
        const vector<int> &inarr,int s,int d,  \
        const int &n){
    if(s>d)return NULL;
    int i,j;
    for(j=0;j<n;++j){
        for(i=s;i<=d;++i)
            if(inarr[i] == levelarr[j]){
                Node *root = new Node(inarr[i]);
                root->left = _CBT_In_Level(levelarr,inarr,s,i-1,n);
                root->right = _CBT_In_Level(levelarr,inarr,i+1,d,n);
                return root;
            }
    }
    return NULL;
}

//按照层序和中序遍历序列，构造二叉树
Node *CBT_In_Level(const vector<int> &levelarr,const vector<int> &inarr){
    int n;
    if((n = levelarr.size()) != inarr.size() || !n)return NULL;
    return _CBT_In_Level(levelarr,inarr,0,n-1,n);
}

//先序遍历
void PreOrderTraverse(Node *root){
    if(!root)return;
    cout << root->data << " ";
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}

//后序遍历
void PostOrderTraverse(Node *root){
    if(!root)return;
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    cout << root->data << " ";
}

//从左向右叶子
void Left2RightLLeaf(Node *root){
    if(!root)return;
    Left2RightLLeaf(root->left);
    if(!root->left && !root->right)cout << root->data << " ";
    Left2RightLLeaf(root->right);
}


int main(){
    vector<int> lvarr;//={1,2,3,6,8,9,7,4,5};
    vector<int> inarr;//={6,2,4,8,5,1,9,3,7};

    int i;
    cin >> i;
    lvarr.push_back(i);
    while(cin.get() != '\n'){
        cin >> i;
        lvarr.push_back(i);
    }

    cin >> i;
    inarr.push_back(i);
    while(cin.get() != '\n'){
        cin >> i;
        inarr.push_back(i);
    }

    Node *root = CBT_In_Level(lvarr,inarr);

    Left2RightLLeaf(root);
    cout << endl;
    PreOrderTraverse(root);
    cout << endl;
    PostOrderTraverse(root);
    cout << endl;
    
    cout << "End\n";
    cin.get();
    return 0;
}