Node* LCA(Node* root, int a, int b){
    if(root == NULL) return NULL;

    if(a < root->data && b < root->data)
        return LCA(root->left, a, b);

    if(a > root->data && b > root->data)
        return LCA(root->right, a, b);

    return root;
}