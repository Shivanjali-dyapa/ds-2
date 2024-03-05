// Single_Linked_List.h
#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
public:
    int data;
    struct Node* next;
};

class Single_Linked_List {
private:
    Node* head;
    Node* tail;
    int num_items;

public:
    Single_Linked_List();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
    ~Single_Linked_List();
    void insert(int index, int item);
    bool remove(size_t index);
    int find(int item) const;
    void display() const;
};

int main();