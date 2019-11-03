
class Data:
    def __init__(self, priority, value):
        self.priority = priority
        self.value = value 
    

def parent(i):
    return i * 2 

def left_child(i):
    return i * 2 

def right_child(i):
    return i * 2 + 1


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


class MinHeap:

    def __init__(self, size=1000):
        self.size = size
        self.n = 0
        self.arr = [None] * (size + 1)


    def __len__(self):
        return self.n 

    def is_empty(self):
        return self.n == 0

    def __bool__(self):
        return not self.is_empty()
    

    def _sift_up(self, start):
        curr =  start
        while self.arr[curr].priority < self.arr[parent(curr)] and curr > 1:
            swap(self.arr, curr, parent(curr))

    def insert(self, data):
        self.n += 1
        self.arr[self.n] = data    
        self._sift_up(self.n)

    # need to implement body 
    def _sift_down(self, start):
        pass 

    def remove(self):
        swap(self.arr, 1, self.n)
        res = self.arr[self.n]
        self.arr[self.n] = None 
        self.n -= 1
        self._sift_down(1)
        return res



def main():
    filename = 'data.txt'
    passed_header = False

    heap = MinHeap()

    fp = open(filename, 'r')
    for line in fp:
        if passed_header:
            priority, fname, lname = line.split()
            print(line)
    fp.close()

    while heap:
        res = heap.remove()
        print(res)
    
        
      
if __name__ == '__main__':
    main()

