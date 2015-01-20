int maxDepth(TreeNode *root)
{
    if (root == NULL) return 0;
    stack<TreeNode *> gray;
    stack<int> depth;
    int out = 0;

    gray.push(root);
    depth.push(1);
    while (!gray.empty()) {
        TreeNode *tmp = gray.top();
        int num = depth.top();
        gray.pop();
        depth.pop();
        if (tmp->left == NULL && tmp->right == NULL) {
            out = num > out ? num : out;
        }
        else {
            if (tmp->left != NULL) {
                gray.push(tmp->left);
                depth.push(num + 1);
            }
            if (tmp->right != NULL) {
                gray.push(tmp->right);
                depth.push(num + 1);
            }
        }
    }
    return out;
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL) 
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
 
 
队列
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //二叉树最大深度（层次遍历，遍历一层高度加1）
    int maxDepth(TreeNode *root) {
        int height = 0,rowCount = 1;
        if(root == NULL){
            return 0;
        }
        //创建队列
        queue<treenode*> queue;
        //添加根节点
        queue.push(root);
        //层次遍历
        while(!queue.empty()){
            //队列头元素
            TreeNode *node = queue.front();
            //出队列
            queue.pop();
            //一层的元素个数减1，一层遍历完高度加1
            rowCount --;
            if(node->left){
                queue.push(node->left);
            }
            if(node->right){
                queue.push(node->right);
            }
            //一层遍历完
            if(rowCount == 0){
                //高度加1
                height++;
                //下一层元素个数
                rowCount = queue.size();
            }
        }
        return height;
    }
  
};</treenode*> 
 
 
栈
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {  
        if(root == NULL) return 0;  
            
        stack<treenode*> S;  
            
        int maxDepth = 0;  
        TreeNode *prev = NULL;  
            
        S.push(root);  
        while (!S.empty()) {  
            TreeNode *curr = S.top();  
                
            if (prev == NULL || prev->left == curr || prev->right == curr) {  
                if (curr->left)  
                    S.push(curr->left);  
                else if (curr->right)  
                    S.push(curr->right);  
            } else if (curr->left == prev) {  
                if (curr->right)  
                    S.push(curr->right);  
            } else {  
                S.pop();  
            }  
            prev = curr;  
            if (S.size() > maxDepth)  
                maxDepth = S.size();  
        }  
        return maxDepth;  
    }  
};
</treenode*> 
 
DFS
/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)return 0;
        int res = INT_MIN;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode *root, int depth, int &res)
    {
        if(root->left == NULL && root->right == NULL && res < depth)
            {res = depth; return;}
        if(root->left)
            dfs(root->left, depth+1, res);
        if(root->right)
            dfs(root->right, depth+1, res);
    }
};
 
层次遍历
 
/**
 * Definition for binary tree
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        //层次遍历树的层数,NULL为每一层节点的分割标志
        if(root == NULL)return 0;
        int res = 0;
        queue<treenode*> Q;
        Q.push(root);
        Q.push(NULL);
        while(Q.empty() == false)
        {
            TreeNode *p = Q.front();
            Q.pop();
            if(p != NULL)
            {
                if(p->left)Q.push(p->left);
                if(p->right)Q.push(p->right);
            }
            else
            {
                res++;
                if(Q.empty() == false)Q.push(NULL);
            }
        }
        return res;
    }
}; </treenode*>