#include <iostream>
using namespace std;

typedef struct bstnode{
    int key;
    int element;
    int height;
    bstnode* left;
    bstnode* right;
}BSTNode;

BSTNode* create_bstnode(int k, int e){
    BSTNode* n = (BSTNode*)malloc(sizeof(BSTNode));
    n->key = k;
    n->element = e;
    n->left = NULL;
    n->right = NULL;
    return n;
}

typedef struct{
    BSTNode* root;
    int nodecount;
}BST;

BST* create_bst(){
    BST* bst = (BST*)malloc(sizeof(BST));
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

int findhelp(BSTNode* rt, int k){
    if (rt == NULL)return NULL;
    if (rt->key > k)return findhelp(rt->left, k);
    else if (rt->key == k)return rt->element;
    else return findhelp(rt->right, k);
}

int find(BST* bst, int k){
    return findhelp(bst->root, k);
}

int h(BSTNode* rt){
    if (rt == NULL)return -1;
    return rt->height;
}

int getBalance(BSTNode* rt){
    if (rt == NULL)return 0;
    return h(rt->left) - h(rt->right);
}

BSTNode* leftRotate(BSTNode* rt){
    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

BSTNode* rightRotate(BSTNode* rt){
    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

BSTNode* inserthelp(BSTNode* rt, int k, int e){
    if (rt == NULL) return create_bstnode(k, e);
    if (rt->key > k)rt->left = inserthelp(rt->left, k, e);
    else rt->right = inserthelp(rt->right, k, e);
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if (balance < -1 && k >= rt->right->key)return leftRotate(rt);
    else if (balance > 1 && k < rt->left->key)return rightRotate(rt);
    else if (balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    else if (balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert(BST* bst, int k, int e){
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

BSTNode* getmin(BSTNode* rt){
    if (rt->left == NULL)return rt;
    return getmin(rt->left);
}

BSTNode* deletemin(BSTNode* rt){
    if (rt->left == NULL) return rt->right;
    rt->left = deletemin(rt->left);
    return rt;
}

BSTNode* removehelp(BSTNode* rt, int k){
    if (rt == NULL) return NULL;
    if (rt->key > k)rt->left = removehelp(rt->left, k);
    else if (rt->key < k)rt->right = removehelp(rt->right, k);
    else{
        if (rt->left == NULL) return rt->right;
        else if (rt->right == NULL)return rt->left;
        else{
            BSTNode* temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int remove(BST* bst, int k){
    int temp = findhelp(bst->root, k);
    if (temp != NULL){
        bst->root = removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

void preorder(BSTNode* rt){
    if (rt != NULL) {
        cout << rt;
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode* rt){
    if (rt != NULL) {
        inorder(rt->left);
        cout << rt;
        inorder(rt->right);
    }
}

void posorder(BSTNode* rt){
    if (rt != NULL) {
        posorder(rt->left);
        posorder(rt->right);
        cout << rt << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    BST* bst = create_bst();
    for(int i=0; i < n; i++){
        string comando;
        cin >> comando;
        if (comando == "insert"){
            int x;
            cin >> x;
            insert(bst, x, x);
        }
        else{
            if(comando == "pre"){
                preorder(bst->root);
            }
            else if (comando == "in"){
                inorder(bst->root);
            }
            else if (comando == "pos"){
                posorder(bst->root);
            }
        }
    }
    return 0;
}
