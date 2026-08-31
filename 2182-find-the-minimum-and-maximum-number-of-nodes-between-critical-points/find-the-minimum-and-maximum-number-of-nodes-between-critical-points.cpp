class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int n = v.size();

        // Less than 3 nodes => no critical points possible
        if (n < 3) return {-1, -1};

        vector<int> idx;

        // Find critical points
        for (int i = 1; i < n - 1; i++) {
            if ((v[i] > v[i - 1] && v[i] > v[i + 1]) ||
                (v[i] < v[i - 1] && v[i] < v[i + 1])) {
                idx.push_back(i);
            }
        }

        // Need at least 2 critical points
        if (idx.size() < 2) return {-1, -1};

        // Maximum distance
        int maxDist = idx.back() - idx.front();

        int minDist = INT_MAX;

        for (int i = 1; i < idx.size(); i++) {
            minDist = min(minDist, idx[i] - idx[i - 1]);
        }

        return {minDist, maxDist};
    }
};
