#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_NAME_LEN 50
#define HASH_TABLE_LEN 1000

using namespace std;

typedef struct
{
    char key[MAX_NAME_LEN];
    int value;
} Data;

Data create_data(char key[], int value)
{
    Data d;
    d.value = value;
    strcpy(d.key, key);
    return d;
}

int keys_equal(char key1[], char key2[])
{
    return strcmp(key1, key2) == 0;
}

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

void print_data(Data d)
{
    cout << '(' << d.key << "," << d.value << ")";
}


typedef struct node
{
    Data data;
    struct node *next;
} Node, *NodePtr;

NodePtr create_node(Data data)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->next = NULL;
    np->data = data;
    return np;
}

typedef struct 
{
    NodePtr head;
    NodePtr last;
} LinkedList, *LinkedListPtr;

LinkedListPtr create_link_list()
{
    LinkedListPtr l = (LinkedListPtr)malloc(sizeof(LinkedList));
    l->head = NULL;
    l->last = NULL;
    return l;
}



void append_data(LinkedListPtr lp, Data data)
{
    NodePtr np = create_node(data);
    if(lp->head == NULL)
    {
        lp->head = np;
        lp->last = np;
    }
    else
    {
        lp->last->next = np;
        lp->last = np;
    }
}

void insert_data(LinkedListPtr lp, Data data)
{
    NodePtr curr = lp->head;
    while(curr != NULL)
    {
        if (keys_equal(curr->data.key, data.key))
        {
            curr->data = data;
            return;
        }
    }
    append_data(lp, data);

}


NodePtr find_node_by_key(LinkedListPtr lp, char key[])
{
    NodePtr curr = lp->head;
    while(curr != NULL)
    {   
        if(keys_equal(curr->data.key, key))
        {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

void print_linked_list(LinkedListPtr lp)
{
    NodePtr curr = lp->head;
    while(curr != NULL)
    {
        print_data(curr->data);
        if(curr->next != NULL)
        {
            cout << "-->";
        }
        curr = curr->next;
    }
}


void delete_node_by_key(LinkedListPtr lp, char key[])
{
    if(lp->head != NULL)
    {
        if(lp->head->next == NULL)
        {
            if(keys_equal(lp->head->data.key, key))
            {
                free(lp->head);
                lp->head = NULL;
            }
        }
        else
        {
            NodePtr prev = lp->head;
            NodePtr curr = prev->next;
            while(curr != NULL && !keys_equal(curr->data.key, key))
            {
                prev = curr;
                curr = prev->next;
            }
            if(curr != NULL)
            {
                prev->next = curr->next;
                free(curr);
            }
        }
        //cout << "Handling unitary case!";
        
    }
}



typedef struct 
{
    LinkedListPtr table[HASH_TABLE_LEN];
} Hashtable, *HashtablePtr;

HashtablePtr create_hashtable()
{
    HashtablePtr ht = (HashtablePtr)malloc(sizeof(Hashtable));
    memset(ht->table, 0, sizeof(LinkedListPtr) * HASH_TABLE_LEN);
    return ht;
}


void insert(HashtablePtr ht, char key[], int value)
{
    Data d = create_data(key, value);
    int loc = string_hash(key) % HASH_TABLE_LEN;
    if(ht->table[loc] == NULL)
    {
        ht->table[loc] = create_link_list();
    }
    insert_data(ht->table[loc], d);
}

NodePtr search(HashtablePtr ht, char key[])
{
    int loc = string_hash(key) % HASH_TABLE_LEN;
    NodePtr np = NULL;
    if(ht->table[loc] != NULL)
    {
        np = find_node_by_key(ht->table[loc], key);
    }
    return np;
}

void delete_entry(HashtablePtr ht, char key[])
{
    int loc = string_hash(key) % HASH_TABLE_LEN;
    if(ht->table[loc] != NULL)
    {
        delete_node_by_key(ht->table[loc], key);
    }
}

int main()
{
    HashtablePtr ht = create_hashtable();
    insert(ht, "Inzamam", 9);
    insert(ht, "Nicholas", 2);
    insert(ht, "Alice", 10);
    NodePtr np = search(ht, "Inzamam");
    print_data(np->data);
    cout << endl;
    NodePtr np1 = search(ht, "Alice");
    print_data(np1->data);
    cout << endl;
    delete_entry(ht, "Alice");
    NodePtr np2 = search(ht, "Alice");
    if(np2 == NULL)
    {
        cout << "Data not found!" << endl;
    }
    else
    {
        print_data(np2->data);
        cout << endl;
    }
     NodePtr np3 = search(ht, "Nicholas");
     if(np3 != NULL)
     {
          print_data(np3->data);
     }
     else
     {
        cout << "Data not found!" << endl;

     }
    
     insert(ht, "Nicholas", 3);
     np3 = search(ht, "Nicholas");
     if(np3 != NULL)
     {
          print_data(np3->data);
     }
     else
     {
        cout << "Data not found!" << endl;
            
     }
    
    return 0;
}