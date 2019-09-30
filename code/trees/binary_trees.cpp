#include <iostream>

using namespace std;

typedef data_t int

typedef struct tree_node
{
  data_t data;
  struct tree_node* left;
  struct tree_node* right;
  struct tree_node* parent;
} TreeNode, *TreeNodePtr

TreeNodePtr make_tree_node(data_t data, TreeNodePtr parent)
{
  TreeNodePtr tnp = (TreeNodePtr)malloc(sizeof(TreeNode));
  tnp->data = data;
  tnp->parent = parent;
  tnp->left = NULL;
  tnp->right = NULL;
  return tp;
}

void TreeNodePtr add_child(TreeNodePtr parent, TreeNodePtr child, int is_left)
{
  child->parent = parent;
  if(is_left)
  {
    parent->left = child;
  }
  else
  {
    parent->right = child;
  }
}



int is_internal(TreeNodePtr tnp)
{
  return (tnp->left != NULL || tnp->right != NULL);
}

int is_external(TreeNodePtr tnp)
{
  return !(is_internal(tnp));
}

int num_descendants(TreeNodePtr tnp)
{
  int count = 0;
  if(tnp->left != NULL)
  {
    count += num_descendants(tnp->left);
  }

  if(tnp->right != NULL)
  {
    count += num_descendants(tnp->right);
  }
  return count;
}

typedef struct
{
  TreeNodePtr root;
} Tree, *TreePtr;

TreePtr create_tree(TreeNodePtr root)
{
  TreePtr tree = (TreePtr)malloc(sizeof(Tree));
  tree->root = root;
  return tree;
}

int is_empty(TreePtr tp)
{
  return tp->root == NULL;
}

int tree_size(TreePtr tp)
{
  if(tp->root == NULL)
    return 0;
  int count = 1 + num_descendants(tp->root);
  return count;
}
