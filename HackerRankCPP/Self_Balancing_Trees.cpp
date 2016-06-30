/*
 * 
 */

#include "Header.h"

//Still have a Segmentation Fault... I hate C/C++

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


int resetHeight(node * root)
{
    int left, right;
    if(root->left != 0)
        left = resetHeight(root->left)+1;
    else
        left = 0;
    if(root->right != 0)
        right = resetHeight(root->right)+1;
    else
        right = 0;
    if(right > left)
        root->ht=right;
    else
        root->ht=left;
    return 0;
}

int getBalanceFactor(node *root)
{
    return (root->left->ht) - (root->right->ht);
}

node *rebalanceNode(node *root)
{
    if(getBalanceFactor(root) < 1)
    {
        if(getBalanceFactor(root->left) > 0)
        {
            //LeftRight Case
            return rotate_LeftRight(root, root->left);
        }
        else
        {
            //LeftLeft Case
            return rotate_Left(root, root->left);
        }
    }
    if(getBalanceFactor(root) > 1)
    {
        if(getBalanceFactor(root) < 0)
        {
            //RightLeft Case
            return rotate_RightLeft(root, root->right);
        }
        else
        {
            //RightRight Case
            return rotate_Right(root, root->right);
        }
    }
    return root;
}

node *insert(node *root, int value)
{
   if(root == 0){
       node *temp = new node;
       temp->val = value;
       temp->left = 0;
       temp->right = 0;
       resetHeight(temp);
       root = temp;
   }
   if(value < root->val){
       if(root->left != 0)
           insert(root->left, value);
       else{
           node *temp = new node;
           temp->val = value;
           temp->left = 0;
           temp->right = 0;
           resetHeight(temp);
           root->left = temp;
       }
   }
   if(value > root->val){
       if(root->right != 0)
           insert(root->right, value);
       else{
           node *temp = new node;
           temp->val = value;
           temp->left = 0;
           temp->right = 0;
           resetHeight(temp);
           root->right = temp;
       }
   }
   //Rebalance Here Holy Shit!
   root = rebalanceNode(root);
   return root;
}