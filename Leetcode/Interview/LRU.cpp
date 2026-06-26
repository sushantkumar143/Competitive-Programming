#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        if(mp.size() == cap) {
            Node* lru = tail->prev;

            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);

        insert(newNode);
        mp[key] = newNode;
    }
};