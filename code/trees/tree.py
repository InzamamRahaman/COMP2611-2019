

class TreeNode:
    def __init__(self, data, parent=None, children=[]):
        self.data = data
        self.parent = parent
        self.children = children

    def is_root(self):
        return self.parent is None

    def is_internal(self):
        return len(self.children) > 0

    def is_external(self):
        return not self.is_internal()

    def get_children(self):
        return self.children

    def add_child(self, child):
        child.parent = self
        self.children.append(child)

    def get_num_descendants(self):
        count = 0
        for child in self.children:
            count += 1
            count += child.get_num_descendants()
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
