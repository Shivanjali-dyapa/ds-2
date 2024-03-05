#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class IntStack {
private:
    vector<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
    }

    void pop() {
        if (!isEmpty()) {
            stack.pop_back();
        } else {
            cout << "Stack is empty. Cannot pop.\n";
        }
    }

    bool isEmpty() const {
        return stack.empty();
    }

    int top() const {
        if (!isEmpty()) {
            return stack.back();
        } else {
            throw logic_error("Stack is empty. Cannot get top element.");
        }
    }

    double getAverage() const {
        if (!isEmpty()) {
            double sum = 0;
            for (int value : stack) {
                sum += value;
            }
            return sum / stack.size();
        } else {
            throw logic_error("Stack is empty. Cannot calculate average.");
        }
    }
};

int main() {
    IntStack myStack;
    
    int choice=1;
    
    while(choice<6 && choice>0)
    {
    cout<<"1.Stack empty or not\n2.To insert element\n3.pop element\n4.Top of stack\n5.Avg of stack\n6.To exit\n";
    cout<<"Enter the option";
    cin>>choice;
    if(choice==1){
       if (myStack.isEmpty()) {
        cout << "Stack is empty.\n";
       } else {
        cout << "Stack is not empty.\n";
       } 
    }
    else if(choice==2){
        
            int a;
            cout<<"Enter the element\n";
            cin>>a;
            myStack.push(a);
        
    }
    else if(choice==3){
        
            myStack.pop();
        
    }
    else if(choice==4){
        cout<<myStack.top()<<endl;
    }
    else if (choice==5){
        try {
            cout << fixed << setprecision(2) << myStack.getAverage() << endl;
        } catch (const logic_error& e) {
            cout << e.what() << endl;
        }
    }
    }
    return 0;
}
