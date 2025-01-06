class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
    vector<int> answer(n, 0);

    int count = 0;  // Count of balls to the left
    int operations = 0;

    // Left-to-right pass
    for (int i = 0; i < n; i++) {
        answer[i] += operations;
        if (boxes[i] == '1') {
            count++;
        }
        operations += count;
    }

    count = 0;  // Count of balls to the right
    operations = 0;

    // Right-to-left pass
    for (int i = n - 1; i >= 0; i--) {
        answer[i] += operations;
        if (boxes[i] == '1') {
            count++;
        }
        operations += count;
    }

    return answer;
    }
};