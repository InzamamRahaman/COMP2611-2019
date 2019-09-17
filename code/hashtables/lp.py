class LinearProbingHashtable:
  def __init__(self, n):
    self.table = [None] * n   
    self.n = n 
  
  def insert(self, key, value):
    i = hash(key) % self.n
    misses = 0
    new_i = (i + misses) % self.n 
    while self.table[new_i] is not None:
      misses += 1
      new_i = (i + misses) % self.n 
    self.table[new_i] = (key, value)

  def search(self, key):
    i = hash(key) % self.n
    misses = 0
    new_i = (i + misses) % self.n 
    while self.table[new_i] is not None:
      k_prime, v_prime = self.table[new_i]
      if k_prime == key:
        return v_prime 
      misses += 1
      new_i = (i + misses) % self.n
    return None

  def delete(self, key):
    i = hash(key) % self.n
    misses = 0
    new_i = (i + misses) % self.n 
    while self.table[new_i] is not None:
      k_prime, v_prime = self.table[new_i]
      if k_prime == key:
        self.table[new_i] = None 
        prev_i = new_i
        curr = misses + 1
        new_i = (i + curr) % self.n 
        while self.table[new_i] is not None:
          self.table[prev_i] = self.table[new_i]
          prev_i = new_i
          curr += 1
          new_i = (i + curr) % self.n
      misses += 1
      new_i = (i + misses) % self.n
      



    
hashtable = LinearProbingHashtable(100)
hashtable.insert('Inzamam', 9)
hashtable.insert('Nicholas', 1)
hashtable.insert('Alice', 10)
print(hashtable.search('Inzamam'))
hashtable.delete('Alice')
print(hashtable.search('Alice'))
