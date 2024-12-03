class ExamRoom {
public:
    int len;
    set<int> st;

    ExamRoom(int n) {
        len = n;
    }

    int seat() {
        if (st.empty()) {
            st.insert(0);
            return 0;
        }

        int prev = -1;
        int max_dist = 0;
        int best_seat = 0;

        for (auto it = st.begin(); it != st.end(); it++) {
            if (prev == -1) {
                // Check distance from 0
                if (*it > max_dist) {
                    max_dist = *it;
                    best_seat = 0;
                }
            } else {
                // Check distance between two occupied seats
                int curr_dist = (*it - prev) / 2;
                if (curr_dist > max_dist) {
                    max_dist = curr_dist;
                    best_seat = prev + curr_dist;
                }
            }
            prev = *it;
        }

        // Check distance from the last occupied seat to the end
        if (len - 1 - *st.rbegin() > max_dist) {
            best_seat = len - 1;
        }

        st.insert(best_seat);
        return best_seat;
    }

    void leave(int p) {
        st.erase(p);
    }
};
