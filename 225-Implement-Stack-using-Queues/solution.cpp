class Stack {
public:
    queue<int> q;
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int q_size = q.size();
        for(int i = 0; i < q_size - 1; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};