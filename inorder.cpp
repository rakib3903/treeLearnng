#include<bits/stdc++.h>
using namespace std;
struct node {
    int info;
    struct node* left;
    struct node* right;
};
struct node* root;
struct node* par;
struct node* head1 = NULL;

stack<int>stk;
void solve() {
    int item;
    cout<<"Add an element : ";
    scanf("%d",&item);
    par = (struct node *) malloc(sizeof(struct node));
    par->info = item;
    par->left = NULL;
    par->right = NULL;

    if(head1 == NULL) {
        root = par;
        head1 = par;
    } else {
        struct node* child = root;
        int pos = 1;
        while(1) {
            if(item < child->info) {

                if(child -> left == NULL){
                child->left = par;
                return;
                }else
                child = child->left;

            } else if(item > child->info) {
                 if(child -> right == NULL){
                child->right = par;
                return;
                }else
                 child = child->right;
            } else{
                printf("The %d exists in position %d.\n",item,pos);
                if(child -> right == NULL){
                child->right = par;
                printf("right\n");
                return;
                }else
                 child = child->right;
            }
            pos++;
        }

    }
    return;
}

void inorder(struct node* root){
 if(root == NULL){
 return;
 }
 inorder(root -> left);
 cout<<root->info<<" ";
 inorder(root -> right);
}

int main() {
    int n;
    cin>>n;
    while(n--) solve();

    inorder(root);
}
