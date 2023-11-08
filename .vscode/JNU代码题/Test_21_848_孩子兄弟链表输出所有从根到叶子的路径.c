struct TreeNode{
    int data;
    TreeNode *FirstKid;
    TreeNode *NextBro;
};
void PrintPath(TreeNode *root, int path[], int pathLength){
    if(root == NULL){
        return;
    }
    path[pathLength] = root->data;
    if(root->FirstKid == NULL){
        for(int i = 0; i < pathLength; i++){
            printf("%d\n", i);
        }
    }
    else{
        PrintPath(root->FirstKid, path, pathLength);
    }
    PrintPath(root->NextBro, path, pathLength);
}
