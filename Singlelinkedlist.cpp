#include <iostream>

using namespace std;

struct Node {
public : 
    int data;
    struct Node* next;
};

class Single_Linked_List {

private : 
    Node* head;
    Node* tail;
    int num_items;

public:
    Single_Linked_List() {
        head = NULL;
        tail = NULL;
        num_items = 0;
    }
    
    void push_front(int data) {
        Node* node = new Node();
        node->data = data;

        node->next = head;
        head = node;
        if (!tail) {
            tail = node;
        }
        num_items++;
    }

    void push_back(int data) {
        Node* node = new Node();
        node->data = data;
        node->next = NULL;
        
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        num_items++;
    }

    void pop_front() {
        if (!head) {
            throw out_of_range("Empty list");
        }
        
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
        num_items--;
        if (!head) {
            tail = NULL;
        }
    }

    void pop_back() {
        if (!head) {
            throw out_of_range("Empty list");
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = NULL;
        }
        num_items--;
    }

    int front() const {
        if (!head) {
            throw out_of_range("Empty list");
        }
        return head->data;
    }

    int back() const {
        if (!tail) {
            throw out_of_range("Empty list");
        }
        return tail->data;
    }

    bool empty() const {
        return num_items == 0;
    }

    int size() const {
        return num_items;
    }

    ~Single_Linked_List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        num_items = 0;
    }
    void insert(int index, int item) {
        if (index > num_items) {
            push_back(item);
        } else if (index == 0) {
            push_front(item);
        } else {
            Node* new_node = new Node(); 
            new_node->data = item;

            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                if (current == NULL) {
                    throw out_of_range("Index out of bounds");
                }
                current = current->next;
            }

            new_node->next = current->next;
            current->next = new_node;
            num_items++;
        }
    }
    
    bool remove(size_t index) {
        if (index >= num_items) {
            return false; 
        }

        if (index == 0) {
            pop_front();
        } else {
            Node* current = head;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;

            if (index == num_items - 1) {
                tail = current; 
            }

            num_items--;
        }

        return true;
    }

    int find(int item) const {
        Node* current = head;
        int position = 0;

        while (current != NULL && current->data != item) {
            current = current->next;
            position++;
        }

        if (current == NULL) {
            return -1; 
        } else {
            return position; 
        }
    }
    void display() const {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
    

int main() {
    Single_Linked_List sll;
    
    int choice=1;
    
    while(choice<10 && choice>0)
    {
    cout<<"1.push_front\n2.push_back\n3.pop_front\n4.pop_back\n5.front,back\n6.empty\n7.insert\n8.remove\n9.find the index\n10.exit\n";
    cout<<"Enter the option";
    cin>>choice;
    if(choice==1){
        int a;
        cout<<"Enter element to push_front\n";
        cin>>a;
        sll.push_front(a);
        sll.display();
    }
    else if(choice==2){
        
        int b;
        cout<<"Enter element to push_back\n";
        cin>>b;
        sll.push_back(b);
        sll.display();
        
    }
    else if(choice==3){
        
        sll.pop_front();
        sll.display();
        
        
    }
    else if(choice==4){
        sll.pop_front();
        sll.display();
    }
    else if(choice==5){
        cout<<sll.front()<<endl;
        cout<<sll.back()<<endl;
    }
    else if(choice==6){
        if (sll.empty()){
        cout<<"Empty\n";
        }
        else{
        cout<<"Not Empty\n";
        }
    }
    else if(choice==7){
        int ind,ele;
        cout<<"Enter the index\n";
        cin>>ind;
        cout<<"Enter the element\n";
        cin>>ele;
        sll.insert(ind,ele);
        sll.display();
    }
    else if(choice==8){
        int ind;
        cout<<"Enter the index\n";
        cin>>ind;
        sll.remove(ind);
        sll.display();
    }
    else if(choice==9){
        int ele;
        cout<<"Enter the element\n";
        cin>>ele;
        cout<<sll.find(ele)<<endl;
        
    }
    }
    return 0;
}
