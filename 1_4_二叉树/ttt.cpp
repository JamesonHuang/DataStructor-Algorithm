void getTree(TreeNode **root, string tree) {
	int i = 0;
	stack<TreeNode*> stack;
	TreeNode *now = NULL;
	*root = new TreeNode(tree[i++] - '0');
	now = *root;
	stack.push(now);
	while (!stack.empty() || now) {
		if (now) {
			if (tree[i]=='#') {
				now->left=NULL;
			}else{
				TreeNode *newNode=new TreeNode(tree[i]-'0');
				stack.push(newNode);
				now->left=newNode;
			}
			now=now->left;
		}else{
			now=stack.top();
			stack.pop();
			if (tree[i]=='#') {
				now->right=NULL;
			}else{
				TreeNode *newNode=new TreeNode(tree[i]-'0');
				stack.push(newNode);
				now->right=newNode;
			}
			now=now->right;
		}
		i++;
	}
}
