#include <bits/stdc++.h>
using namespace std;


const string goal = "123456780";
const vector<int> dx = {-1, 1, 0, 0};
const vector<int> dy = {0, 0, -1, 1};

string boardToString(vector<vector<int>>& board) {
    string result = "";
    for (auto& row : board) {
        for (auto& num : row) {
            result += to_string(num);
        }
    }
    return result;
}

vector<vector<int>> stringToBoard(string& state) {
    vector<vector<int>> board(3, vector<int>(3));
    for (int i = 0; i < 9; ++i) {
        board[i / 3][i % 3] = state[i] - '0';
    }
    return board;
}

vector<string> getNextStates(string& state) {
    int zeroPos = state.find('0');
    int x = zeroPos / 3;
    int y = zeroPos % 3;
    vector<string> nextStates;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            string newState = state;
            swap(newState[zeroPos], newState[nx * 3 + ny]);
            nextStates.push_back(newState);
        }
    }

    return nextStates;
}

int bfs(string& start) {
    if (start == goal) return 0;

    unordered_map<string, int> visited;
    queue<string> q;
    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        int currentDepth = visited[current];

        for (auto& nextState : getNextStates(current)) {
            if (visited.find(nextState) == visited.end()) {
                visited[nextState] = currentDepth + 1;
                if (nextState == goal) {
                    return visited[nextState];
                }
                q.push(nextState);
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> board(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    string start = boardToString(board);
    int result = bfs(start);
    cout << result << endl;

    return 0;
}
