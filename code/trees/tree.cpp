#include <iostream>
#include <cstdlib>

#define MAX_NUM_CHILDREN 100

using namespace std;

typedef data_t int

typedef struct tree_node
{
  data_t data;
  int num_children = 0;
  struct tree_node* children[MAX_NUM_CHILDREN];
  struct tree_node* parent;
} TreeNode, *TreeNodePtr

TreeNodePtr make_tree_node(data_t data, TreeNodePtr parent)
{
  TreeNodePtr tnp = (TreeNodePtr)malloc(sizeof(TreeNode));
  tnp->data = data;
  tnp->num_chilren = 0;
  tnp->parent = parent;
  memset(tnp->children, 0, sizeof(TreeNodePtr) * MAX_NUM_CHILDREN);
  return tp;
}

void TreeNodePtr add_child(TreeNodePtr parent, TreeNodePtr child)
{
  child->parent = parent;
  if(parent->num_children < MAX_NUM_CHILDREN)
  {
    parent->children[parent->num_children] = child;
    parent->num_children += 1
  }
}

int is_internal(TreeNodePtr tnp)
{
  return (tnp->num_children > 0);
}

int is_external(TreeNodePtr tnp)
{
  return !(is_internal(tnp));
}

int num_descendants(TreeNodePtr tnp)
{
  int count = 0;
  for(int i = 0; i < tnp->num_children; i++)
  {
    count += num_descendants(tnp->children[i]);
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
