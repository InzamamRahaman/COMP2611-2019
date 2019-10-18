
class Data:
    def __init__(self, key, value=None):
        self.key = key 
        self.value = value 
    
    def __str__(self):
        return f'Data(key={self.key}, value={self.value})'
    
    def __repr__(self):
        return str(self)

class TreeNode:
    def __init__(self, data, parent=None, left=None, right=None):
        self.data = data   
        self.parent = parent 
        self.left = left 
        self.right = right 

    def __str__(self):
        return f'TreeNode({str(self.data)})'
    
    def __repr__(self):
        return str(self)

    def num_descendants(self):
        count = 0
        if self.left is None:
            count += 1
            self.left.num_descendants()
        
        if self.right is None:
            count += 1
            self.right.num_descendants()
        
        return count




def insert_helper(root, key, value):
    if key < root.data.key:
        if root.left is None:
            data = Data(key, value)
            root.left = TreeNode(data, root)
        else:
            insert_helper(root.left, key, value)
    elif key > root.data.key:
        if root.right is None:
            data = Data(key, value)
            root.right = TreeNode(data, root)
        else:
            insert_helper(root.right, key, value)
    else:
        return

def search_helper(root, key):
    if root is None:
        return None 
    if root.data.key == key:
        return root
    if key < root.data.key:
        return search_helper(root.left, key)
    return search_helper(root.right, key) 

    
def range_query_helper(root, lo, hi):
    if root is None:
        return []
    res = []
    if root.data.key >= lo and root.data.key <= hi:
        res.append(root)
    res_from_left = range_query_helper(root.left, lo, hi)
    res_from_right = range_query_helper(root.right, lo, hi)
    res = res_from_left + res + res_from_right
    return res

def range_query(root, lo, hi):
    if root is None:
        return []
    if root.data.key >= lo and root.data.key <= hi:
        return range_query_helper(root, lo, hi)
    if root.data.key < lo:
        return range_query(root.right, lo, hi)
    return range_query(root.left, lo, hi)
    

def lte_query(root, key):
    if root is None:
        return None 
    
    if root.data.key == key:
        return root 
    
    if root.data.key < key:
        others = lte_query(root.right, key)
        if others is None:
            return root
        else:
            return others 
    return lte_query(root.left, key)

# Need to implement on own!
def gte_query(root, key):
    return []


def to_array(root, arr, index):
    if root is not None:
        arr[index] = root.data.key 
        to_array(root.left, arr, index * 2)
        to_array(root.right, arr, index * 2 + 1)

def get_height(root):
    if root is None:
        return 0
    return 1 + max(get_height(root.left), get_height(root.right))


class BinarySearchTree:
    def __init__(self):
        self.root = None 

    def is_empty(self):
        return self.root is None 

    def __bool__(self):
        return not self.is_empty()

    def num_nodes(self):
        if self.root is None:
            return 0
        return self.root.num_descendants()

    def __len__(self):
        return self.num_nodes()
    
    # def is_empty(self):
    #     return self.root is None 
    
    def insert(self, key, value=None):
        if self.root is None:
            data = Data(key, value)
            self.root = TreeNode(data)
        else:
            insert_helper(self.root, key, value)

    def search(self, key):
        return search_helper(self.root, key)

    def __contains__(self, key):
        return self.search(key) is not None

    def __getitem__(self, key):
        node = self.search(key)
        if node is None:
            return None 
        return node.data.value 

    def __setitem__(self, key, value=None):
        node = self.search(key)
        if node is None:
            self.insert(key, value)
        else:
            node.data.value = value 

    def range_query(self, hi, lo):
        return range_query(self.root, hi, lo)

    def lte_query(self, key):
        return lte_query(self.root, key)

    def gte_query(self, key):
        return gte_query(self.root, key)

    def get_height(self):
        return get_height(self.root) - 1

    def to_array(self):
        height = self.get_height()
        max_nodes = 2 ** (height + 1) - 1
        arr = [None] * (max_nodes + 1)
        to_array(self.root, arr, 1)
        return arr

    


    

bst = BinarySearchTree()
bst.insert(23)
bst.insert(14)
bst.insert(54)
bst.insert(10)
bst.insert(100)
bst.insert(40)
bst.insert(-1)
bst.insert(15)

print(bst.to_array())
print(bst.lte_query(16))
print(bst.range_query(13, 45))