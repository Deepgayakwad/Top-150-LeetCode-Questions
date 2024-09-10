class MinStack {
public:
    stack<long long> st; // Use long long for the stack
    long long mini;      // Use long long for the minimum value

    MinStack() {
        mini = LLONG_MAX; // Initialize mini with long long max value
    }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val > mini) {
                st.push(val);
            } else {
                st.push(2LL * val - mini); // Use 2LL to ensure long long multiplication
                mini = val;
            }
        }
    }
    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2LL * mini - x; // Use 2LL to ensure long long multiplication
        }
    }

    int top() {
        if (st.empty()) {
            return -1; // or throw an exception
        }
        long long x = st.top();
        if (x < mini) {
            return mini;
        } else {
            return x;
        }
    }

    int getMin() {
        return mini;
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