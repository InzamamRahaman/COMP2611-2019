
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



def insert_helper(root, key, value):
    if root.data.key < key:
        if root.left is None:
            data = Data(key, value)
            root.left = TreeNode(data, root)
        else:
            insert_helper(root.left, key, value)
    if root.data.key < key:
        if root.right is None:
            data = Data(key, value)
            root.right = TreeNode(data, root)
        else:
            insert_helper(root.right, key, value)

def search_helper(root, key):
    if root is None:
        return None 
    if root.data.key == key:
        return root
    if root.data.key < key:
        return search_helper(root.left, key)
    return search_helper(root.right, key) 

    
def range_query_helper(root, hi, lo):
    if root is None or root.data.key > hi or root.data.key < lo:
        return []
    res = [root]
    res_from_left = range_query_helper(root.left, hi, lo)
    res_from_right = range_query_helper(root.right, hi, lo)
    res = res_from_left + res + res_from_right
    return res

def range_query(root, hi, lo):
    if root is None:
        return []
    if root.data.key >= lo and root.data.key <= hi:
        return range_query_helper(root, hi, lo)
    if root.data.key < lo:
        return range_query_helper(root.right, hi, lo)
    return range_query_helper(root.left, hi, lo)
    

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
    return None 

def gte_query(root, key):
    return None

class Tree:
    def __init__(self):
        self.root = None 
    
    def is_empty(self):
        return self.root is None 
    
    def insert(self, key, value=None):
        if self.root is None:
            data = Data(key, value)
            self.root = TreeNode(data)
        else:
            insert_helper(self.root, key, value)

    def search(self, key):
        return search_helper(self.root, key)

    def range_query(self, hi, lo):
        return range_query(self.root, hi, lo)

    def lte_query(self, key):
        return lte_query(self.root, key)

    def gte_query(self, key):
        return gte_query(self.root, key)

    

    

