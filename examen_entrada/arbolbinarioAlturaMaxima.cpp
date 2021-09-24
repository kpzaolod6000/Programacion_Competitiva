#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int val;
        Node *left;
        Node*right;
        Node() : val(0), left(), right() {}
        Node(int x) : val(x), left(), right() {}
        Node(int x, Node*left, Node*right) : val(x), left(left), right(right) {}
};

Node* Show(vector<int> &nums, int start, int end){

    if(start > end)
        return nullptr;
    
    int mid = start + (end - start)/2;
    Node* root = new Node(nums[mid]);

    root->left = Show(nums,start,mid-1);
    root->right = Show(nums,mid+1,end);

    return root;    
}

Node* TreeBinary(vector<int> &array){

    int n=array.size();
    Node* root = Show(array,0,n);
    return root;

}

void preOrder(Node* root){
    if(root != nullptr){
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main(){

    vector<int> array1= {2,5,8,14,55};
    Node* root1 = TreeBinary(array1);
    preOrder(root1);

    cout << endl;

    vector<int> array2 = {2,-18,50,6,10};
    Node* root2 = TreeBinary(array2);
    preOrder(root2);

    return 0;
}