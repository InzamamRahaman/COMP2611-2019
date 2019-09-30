class TreeNode:
    def __init__(self, data, parent=None, left=None, right=None):
        self.data = data
        self.parent = parent
        # direct access to modify children
        self.left = left
        self.right = right

    def is_root(self):
        return self.parent is None

    def has_left(self):
        return self.left is not None

    def has_right(self):
        return self.right is not None

    def is_internal(self):
        return self.left is None and self.right is None

    def is_external(self):
        return not self.is_internal()

    def get_num_descendants(self):
        count = 0
        if self.has_left():
            count += 1 + left.get_num_descendants()
        if self.has_right():
            count += 1 + right.get_num_descendants()
        return count

class Tree:
    def __init__(self, root=None):
        self.root = root

    def is_empty(self):
        return self.root is None

    def size(self):
        if self.root is not None:
            count = 1 + self.root.get_num_descendants()
            return count
        return 0
