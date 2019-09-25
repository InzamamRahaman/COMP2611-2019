#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_NAME_LEN 50
#define HASH_TABLE_LEN 1001
#define COMPUTE_NEW_INDEX(index, misses) ((index + misses) % HASH_TABLE_LEN)

using namespace std;

long string_hash(char* s)
{
  long code = 0;
  long i = 1;
  while(*s)
  {
    code += (long)(s) * i; 
    i += 1;
    s += 1;
  }
  return code;
}


typedef struct 
{
    char key[MAX_NAME_LEN];
    int value;
} Data, *DataPtr;

DataPtr create_data_ptr(char key[], int value)
{
    DataPtr dp = (DataPtr)malloc(sizeof(Data));
    strcpy(dp->key, key);
    dp->value = value;
    return dp;
}

int keys_equal(char key1[], char key2[])
{
    return strcmp(key1, key2) == 0;
}

DataPtr print_data_ptr(DataPtr dp)
{
    cout << "Key: " << dp->key << " Value: " << dp->value;
}

typedef struct 
{
    DataPtr table[HASH_TABLE_LEN];
} Hashtable, *HashtablePtr;

HashtablePtr create_hashtable()
{
    
    HashtablePtr htp = (HashtablePtr)malloc(sizeof(Hashtable));
    memset(htp->table, 0, sizeof(DataPtr) * HASH_TABLE_LEN);
    return htp;
}

void insert(HashtablePtr htp, char key[], int value)
{
    int index = string_hash(key) % HASH_TABLE_LEN;
    int misses = 0;
    DataPtr dp = create_data_ptr(key, value);
    
    int loc = COMPUTE_NEW_INDEX(index, misses);
    DataPtr f = htp->table[loc];
    
    while(htp->table[loc] != NULL)
    {
        if(keys_equal(htp->table[loc]->key, key))
        {
            htp->table[loc]->value = value;
            return;
        }
        misses += 1;
        loc = COMPUTE_NEW_INDEX(index, misses);
    }
    htp->table[loc] = dp;
    // strcpy(htp->table[loc]->key, key);
    // htp->table[loc]->value = value;
}


DataPtr search(HashtablePtr htp, char key[])
{
    int index = string_hash(key) % HASH_TABLE_LEN;
    int misses = 0;
    DataPtr dp = NULL;
    int loc = COMPUTE_NEW_INDEX(index, misses);
    while(htp->table[loc] != NULL)
    {
        if(keys_equal(htp->table[loc]->key, key))
        {
            dp = htp->table[loc];
            break;
        }
        misses += 1;
        loc = COMPUTE_NEW_INDEX(index, misses);
    }
    return dp; 
}

void delete_entry(HashtablePtr htp, char key[])
{
    int index = string_hash(key) % HASH_TABLE_LEN;
    int misses = 0;
    DataPtr dp = NULL;
    int loc = COMPUTE_NEW_INDEX(index, misses);
    while(htp->table[loc] != NULL)
    {
        if(keys_equal(htp->table[loc]->key, key))
        {
            htp->table[loc] = NULL;
            int curr = misses + 1;
            int loc1 = COMPUTE_NEW_INDEX(index, curr);
            while(htp->table[loc1] != NULL)
            {
                htp->table[loc] = htp->table[loc1];
                loc = loc1;
                curr += 1;
                loc1 = COMPUTE_NEW_INDEX(index, curr);
            }
        }
        misses += 1;
        loc = COMPUTE_NEW_INDEX(index, misses);
    }
}


int main()
{
    HashtablePtr ht = create_hashtable();
    
    insert(ht, "Inzamam", 9);
    insert(ht, "Nicholas", 2);
    insert(ht, "Alice", 10);
    DataPtr dp = search(ht, "Inzamam");
    print_data_ptr(dp);
    cout << endl;
    DataPtr dp1 = search(ht, "Alice");
    print_data_ptr(dp1);
    cout << endl;
    delete_entry(ht, "Alice");
    DataPtr dp2 = search(ht, "Alice");
    if(dp2 == NULL)
    {
        cout << "Data not found!" << endl;
    }
    else
    {
        print_data_ptr(dp2);
        cout << endl;
    }
     DataPtr dp3 = search(ht, "Nicholas");
     if(dp3 != NULL)
     {
          print_data_ptr(dp3);
     }
     else
     {
        cout << "Data not found!" << endl;

     }
    
     insert(ht, "Nicholas", 3);
     dp3 = search(ht, "Nicholas");
     if(dp3 != NULL)
     {
          print_data_ptr(dp3);
     }
     else
     {
        cout << "Data not found!" << endl;
            
     }
    
    return 0;

}