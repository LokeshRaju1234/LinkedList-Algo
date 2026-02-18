class Node
{
    public:
    int key,value;
    Node* prev,*next;

    Node(int a,int b)
    {
        key = a;
        value = b;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    Node* head;
    Node* tail;
    int cap;
    int size;
    Node* arr[10005];
    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    LRUCache(int capacity) 
    {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;

        for(int i = 0;i<10000;i++)
        {
            arr[i] = NULL;
        }
    }


    
    int get(int key) 
    {

        if(arr[key] == NULL) return -1; 

        Node* node = arr[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        int currentsize;
        if(arr[key] != NULL)
        {
            Node* node = arr[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
        }
        else
        {
            if(cap == 0)return;


            for(int i = 0;i<10000;i++)
            {
                if(arr[i] != NULL)currentsize++;
            }

            if(cap == currentsize)
            {
                Node* lru = tail->prev;
                removeNode(lru);
                arr[lru->key] = NULL;
                delete lru;
            }

            Node* newNode = new Node(key,value);
            addToFront(newNode);
            arr[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */