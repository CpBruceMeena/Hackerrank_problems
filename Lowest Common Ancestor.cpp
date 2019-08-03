#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

        int min(int a, int b){
            return(a<=b?a:b);
        }
    
        int max(int a, int b){
            return(a>=b?a:b);
        }

        Node *lca(Node *root, int v1,int v2) {
            // Write your code here.
            if(root == NULL) return NULL;
            else{
                int a  = min(v1, v2);
                int b = max(v1, v2);
                
                if(root->data < a and root->data < b){
                    return(lca(root->right, a, b));
                }
                else if(root->data > a and root->data > b){
                    return(lca(root->left, a, b));
                }
                
                return root;
            }
        }
}; //End of Solution
