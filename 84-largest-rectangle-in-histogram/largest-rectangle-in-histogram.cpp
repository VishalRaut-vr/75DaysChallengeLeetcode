class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> s;

        // right smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && height[s.top()] >= height[i]) {
                s.pop();
            }
            if (s.empty()) {
                right[i] = n;
            } else {
                right[i] = s.top();
            }
            s.push(i);
        }
        // empty the stack
        while (!s.empty()) {
            s.pop();
        }
        // left smaller elements
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && height[s.top()] >= height[i]) {
                s.pop();
            }
            if (s.empty()) {
                left[i] = -1;
            } else {
                left[i] = s.top();
            }
            s.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int current = height[i] * width;
            ans = max(ans, current);
        }
        return ans;
    }
};