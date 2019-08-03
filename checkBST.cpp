/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    #include<limits.h>
    bool checkBSTUtil(Node* root,long long int l,long long int r){
        if(!root) return true;
        if(root->data > r or root->data < l) return (false);
        else{
            return(checkBSTUtil(root->left, l, root->data-1) and 
                   checkBSTUtil(root->right, root->data+1, r));
        }        
    }

	bool checkBST(Node* root) {
		
        long long int l = INT_MIN, r = INT_MAX;
        if(root->data > r or root->data < l) return (false);
        else{
            return(checkBSTUtil(root->left, l, root->data-1) and 
                   checkBSTUtil(root->right, root->data+1, r));
        }
	}
