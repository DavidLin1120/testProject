/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* BST(int* nums, int start, int end){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    if(start > end)
        return NULL;
    
    node->val = nums[(start+end)/2];
    node->left = BST(nums, start, (start+end)/2-1);
    node->right = BST(nums,  (start+end)/2+1,end);
    
    return node;
    
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* head;
    if(numsSize==0 || nums==NULL)
        return NULL;
    head = BST(nums,0, numsSize-1);
    return head;
    
}