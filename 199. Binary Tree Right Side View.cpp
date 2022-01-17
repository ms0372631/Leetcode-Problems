
vector<int> rightSideView(TreeNode *root)
{
  vector<int> res;
  dfs(root, 1, res);
  return res;
}

void dfs(TreeNode *root, int depth, vector<int> &res)
{
  if (!root)
    return;
  if (res.size() < depth)
    res.resize(res.size() + 1);
  res[depth - 1] = root->val;
  dfs(root->left, depth + 1, res);
  dfs(root->right, depth + 1, res);
}