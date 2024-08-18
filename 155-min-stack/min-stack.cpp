class MinStack {
public:
    stack<long long> st;
    long long mini = LLONG_MAX;

    MinStack() { }

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val > mini) {
                st.push(val);
            } else {
                long long newval = 2 * (long long)val - mini;
                mini = val;
                st.push(newval);
            }
        }
    }

    void pop() {
        if (st.top() > mini) {
            st.pop();
        } else {
            // Rollback to the previous minimum value
            long long newval = st.top();
            mini = 2 * mini - newval;
            st.pop();
        }
    }

    int top() {
        if (st.top() > mini) {
            return st.top();
        } else {
            return mini;
        }
    }

    int getMin() {
        return mini;
    }
};
