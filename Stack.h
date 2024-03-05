// IntStack.h
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class IntStack {
private:
    vector<int> stack;

public:
    void push(int value);
    void pop();
    bool isEmpty() const;
    int top() const;
    double getAverage() const;
};

int main();