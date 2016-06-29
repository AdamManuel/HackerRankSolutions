/*
 * 
 */

#include "Header.h"

node *rotate_Right(node *x, node *z)
{
    node *temp = z->left;
    x->right = temp;
    z->left = x;
    return z;
}

node *rotate_Left(node *x, node *z)
{
    node *temp = z->right;
    x->left = temp;
    z->right = x;
    return z;
}

node *rotate_RightLeft(node *x,node *z)
{
    node *y = z->left;
    node *temp1 = y->right;
    z->left = temp1;
    y->right = z;
    node *temp2 = y->left;
    z->right = temp2;
    y->left = x;
    return y;
}

node *rotate_LeftRight(node *x, node *z)
{
    node *y = z->right;
    node *temp1 = y->left;
    z->right = temp1;
    y->left = z;
    node *temp2 = y->right;
    z->left = temp2;
    y->right = x;
    return y;
}


int getHeight(node * root)
{
    int left, right;
    if(root->left != 0)
        left = getHeight(root->left)+1;
    else
        left = 0;
    if(root->right != 0)
        right = getHeight(root->right)+1;
    else
        right = 0;
    if(right > left)
        return right;
    else
        return left;
}

int getBalanceFactor(node *root)
{
    return getHeight(root->left) - getHeight(root->right);
}

void preOrderRebalance(node *root) {
    if(getBalanceFactor(root) > 1)
    {
        if(getBalanceFactor(root->left) < -1)
        {
            rotate_LeftRight(root, root->left);
        }
        else
            rotate_Left(root, root->left);
    }
    if(getBalanceFactor(root) < -1)
    {
        if(getBalanceFactor(root->right) > 1)
        {
            rotate_RightLeft(root, root->right);
        }
        else
            rotate_Right(root, root->left);
    }
    if(root->left != 0)
    {
        preOrderRebalance(root->left);
    }
    if(root->right != 0)
    {
        preOrderRebalance(root->right);
    }
}

node *insert_unordered(node *root, int value)
{
   if(root == 0){
       node *temp = new node;
       temp->val = value;
       temp->left = 0;
       temp->right = 0;
       root = temp;
   }
   if(value < root->val){
       if(root->left != 0)
           insert_unordered(root->left, value);
       else{
           node *temp = new node;
           temp->val = value;
           temp->left = 0;
           temp->right = 0;
           root->left = temp;
       }
   }
   if(value > root->val){
       if(root->right != 0)
           insert_unordered(root->right, value);
       else{
           node *temp = new node;
           temp->val = value;
           temp->left = 0;
           temp->right = 0;
           root->right = temp;
       }
   }
   return root;
}

node *insert(node *root, int value)
{
    insert_unordered(root, value);
    preOrderRebalance(root);
    return root;
}