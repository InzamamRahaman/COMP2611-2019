class ChainingHashtable:
  def __init__(self, n):
    # create blank list with n elements
    self.table = [None] * n  
    self.n = n
  
  def insert(self, key, value):
    i = hash(key) % self.n
    if self.table[i] is None:
      self.table[i] = [(key, value)]
    else:
      inserted = False
      for j, (k_prime, v_prime) in enumerate(self.table[i]):
        if key == k_prime:
          self.table[i][j] = value 
          inserted = True 
      if inserted == False:
        self.table[i].append((key, value))
  def search(self, key):
    i = hash(key) % self.n
    if self.table[i] is None:
      return None 
    for (k_prime, v_prime) in self.table[i]:
      if key == k_prime:
        return v_prime
    return None
    
    

  def delete(self, key):
    i = hash(key) % self.n
    if self.table[i] is not None:
      for j, (k_prime, v_prime) in enumerate(self.table[i]):
        if key == k_prime:
          # Python remove element from index j 
          # moves all other elements up accordingly
          self.table[i].pop(j)


hashtable = ChainingHashtable(100)
hashtable.insert('Inzamam', 9)
hashtable.insert('Nicholas', 1)
hashtable.insert('Alice', 10)
print(hashtable.search('Inzamam'))
hashtable.delete('Alice')
print(hashtable.search('Alice'))
