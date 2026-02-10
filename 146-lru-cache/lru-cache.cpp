#include <unordered_map>
using namespace std;

class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head
    void insert(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    // Delete node from DLL
    void deleteNode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        int ans = node->val;

        mp.erase(key);
        deleteNode(node);
        insert(node);
        mp[key] = head->next;

        return ans;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            mp.erase(key);
            deleteNode(existing);
        }

        if(mp.size() == capacity) {
            Node* lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        Node* node = new Node(key, value);
        insert(node);
        mp[key] = head->next;
    }
};
