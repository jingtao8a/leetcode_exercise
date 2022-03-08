#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

   void mydeserialize(TreeNode*& root, string& data) {
        if (data.empty()) return;
        int pos = data.find(',');
        string str;
        if (pos != -1) {
            str = data.substr(0, pos);
            data = data.substr(pos + 1);
        } else {
            str = data;
        }

        if (str == "#") {
            root = NULL;
            return;
        } else {
            root = new TreeNode(stoi(str));
            mydeserialize(root->left, data);
            mydeserialize(root->right, data);
        }
    }
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        mydeserialize(root, data);
        return root;
    }
    
void inorder(TreeNode* root) {
	if (root == NULL) return;
	cout << root->val<< " ";
	inorder(root->left);
	inorder(root->right);
}
    void myserialize(TreeNode* root, string& data) {
        if (root == NULL) {
            data = data + "#";
            return;
        }
        data = data + to_string(root->val);
        data = data + ",";
        myserialize(root->left, data);
        data = data + ",";
        myserialize(root->right, data);
    }
string serialize(TreeNode* root) {
        string data;
        myserialize(root, data);
        return data;
    }

    
int main()
{
	TreeNode* root = deserialize("12,32,#,#,321,2,#,#,#");
	inorder(root);
	cout << serialize(root);
 	return 0;
}
