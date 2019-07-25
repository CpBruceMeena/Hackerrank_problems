#include <bits/stdc++.h>

using namespace std;

class node{
    public: 
        int data;
        node* left = NULL;
        node* right = NULL;
};

node* newnode(int key){
    node* temp = new node;
    temp->data = key;
    return temp;
}

int max(int a, int b){
    return(a>=b?a:b);
}

int height(node* root){
    if(!root) return 0;
    else{
        return(max(height(root->left),height(root->right)) + 1);
    }
}

node* push(node* root, int l, int r, int key){
    if(!root) return NULL;
    if((root)->data != key){
            push((root)->left, l, r, key);
            push((root)->right, l, r, key);
        
    }
    else {
        if(l != -1){
        (root)->left = newnode(l);
         }
        if(r != -1){
        (root)->right = newnode(r);
        }
    }
    return root;
}

void printInorder(node* root, vector<int> &upload){
    if(!root) return;
    printInorder(root->left, upload);
    upload.push_back(root->data);
    printInorder(root->right, upload);
}

void swap(node* root, int level, vector<int>& front){
    if(!root) return;
    if(level == 1){
        front.push_back(root->data);
        return;
    }
    swap(root->left, level-1, front);
    swap(root->right, level-1, front);
}

void swapindividual(node* root, int key){
    if(!root) return;
    if(root->data == key){
        if(root->left == NULL and root->right == NULL) return;
        node* current = root->left;
        root->left = root->right;
        root->right = current;
        return;
    }
    swapindividual(root->left, key);
    swapindividual(root->right,key);
}

void print(node* root){
    if(!root) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = indexes.size();
    node* root = new node;
    root->data = 1;
    node* head = root;
    for(int i = 0; i<n; i++){
        push(root, indexes[i][0], indexes[i][1], i+1);
    }
    int h = height(root);
    vector<vector<int> > result;
    for(int i = 0; i<queries.size(); i++){
        vector<int> upload;
        int temp = queries[i];
        int t = temp;
        while(temp < h){
            vector<int> front;
            swap(root, temp, front);
            for(int j = 0; j<front.size(); j++){
                swapindividual(root, front[j]);
            }
        //    print(root);
        //    cout<<endl;
            temp += t;
        }
        printInorder(root, upload);
        result.push_back(upload);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
