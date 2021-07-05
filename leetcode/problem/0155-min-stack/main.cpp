#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class MinStack {
    vector<int> mainStack;
    vector<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    // 這裡很重要，思考誤區是 minStack 這樣設計怎會成功
    // 關鍵因素是這是 stack，你只能從最尾巴 pop。
    
    // ex.   X, Y, Z > 1
    // mainStack = [1, X, Y, Z, 0]
    // minStack = [1, 0]
    
    // mainStack 在 pop XYZ 時都不重要，因為 min 不變
    
    void push(int val) {
        mainStack.push_back(val);
        if (minStack.empty() || val <= minStack.back())
            minStack.push_back(val);
    }
    
    void pop() {
        int val = mainStack.back();
        mainStack.pop_back();
        if (minStack.back() == val)
            minStack.pop_back();
    }
    
    int top() {
        return mainStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    return 0;
}