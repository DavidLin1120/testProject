/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder_trav(struct TreeNode* node, int* returnSize, int* returnArray){
    
    if (node == NULL)
        return;
    
    inorder_trav(node->left, returnSize, returnArray);
   
    returnArray[*returnSize] = node->val;
    (*returnSize)++;
    
    inorder_trav(node->right, returnSize, returnArray);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *returnArray;
    returnArray = malloc(101*sizeof(int));
    
    *returnSize=0;
    inorder_trav(root, returnSize, returnArray);
    return returnArray;
    
}

