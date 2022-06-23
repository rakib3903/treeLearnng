#include<bits/stdc++.h>
using namespace std;


struct node {
    int info;
    node* left;
    node* right;
};


node* crtNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode -> info = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}


node* Insert(node* root, int data) {
    if(root == NULL) {
        root = crtNode(data);
    } else if(data < root -> info) {
        root -> left = Insert(root -> left, data);
    } else {
        root -> right = Insert(root -> right, data);
    }
    return root;
}


bool Search(node* root, int data) {
    if(root == NULL) {
        return false;
    } else if(root -> info == data) {
        return true;
    }
    else if(data <  root -> info) {
        return Search(root -> left,data);
    } else {
        return Search(root -> left,data);
    }
}




void preorder(struct node* root) {
    if(root == NULL) return;
    cout<<root->info<<" ";
    preorder(root -> left);
    preorder(root -> right);
}


void inorder(struct node* root) {
    if(root == NULL) return;
    inorder(root -> left);
    cout<<root->info<<" ";
    inorder(root -> right);
}


void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout<<root->info<<" ";
}


int main() {
    node* root = NULL;
    root = Insert(root,4);
    root = Insert(root,2);
    root = Insert(root,5);
    root = Insert(root,1);
    root = Insert(root,3);


    cout<<"Preorder traversing of tree is as follows : "<<endl;
    preorder(root);
    cout<<endl;


    cout<<"Inorder traversing of tree is as follows : "<<endl;
    inorder(root);
    cout<<endl;


    cout<<"Posteorder traversing of tree is as follows : "<<endl;
    postorder(root);
    cout<<endl;


    bool bol = Search(root,4);
    if(bol == true){
    cout<<"the element exists!"<<endl;
    }
    else{
    cout<<"the element does not exist!"<<endl;
    }


    bool bol1 = Search(root,10);
    if(bol1 == true){
    cout<<"the element exists!"<<endl;
    }
    else{
    cout<<"the element does not exist!"<<endl;
    }


    return 0;
}
