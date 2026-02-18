#include <unordered_map>
using namespace std;

class LRUCache {
public:

    // Doubly Linked List Node
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Constructor
    LRUCache(int cap) {
        capacity = cap;

        // dummy nodes (sentinel nodes)
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Insert node right after head (most recently used)
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // GET operation
    int get(int key) {

        // not found
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // move to front (recently used)
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    // PUT operation
    void put(int key, int value) {

        // key already exists → update + move to front
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            insertAfterHead(node);
        }
        else {
            // cache full → remove LRU
            if(mp.size() == capacity) {
                Node* lru = tail->prev;

                deleteNode(lru);
                mp.erase(lru->key);
            }

            // insert new node
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};