

class Node:
    def __init__(self, data, prev=None, next=None):
        self.data = data   
        self.prev = prev  
        self.next = next 
    
    def __str__(self):
        return str(self.data)

    def __repr__(self):
        return str(self.data)


class DoublyLinkedList:
    def __init__(self):
        self.head = None 
        self.tail = None 
    
    def insert(self, data):
        # Fill out code here
        
    
    def __str__(self):
        # fill out code here
    
    def __len__(self):
        n = 0
        curr = self.head 
        while curr is not None:
            n += 1 
            curr = self.curr.next 
        return curr

    def __repr__(self):
        return str(self)

    def merge(self, other):
        self.prev.next = other.head 
    

ll = DoublyLinkedList()
ll.insert(3)
ll.insert(34)
ll.insert(0)
ll.insert(76)
print(ll)




            
