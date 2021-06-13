#include<bits/stdc++.h>
//#define DEBUG
//#define RECURSIVE

using namespace std;

class FloodFill {
    public:
        FloodFill(int xDim, int yDim) : matrix(xDim)
#ifndef RECURSIVE
                                        ,visited(xDim)
#endif
        {
            for(int i = 0; i < xDim; i++) {
                matrix[i].resize(yDim);
            }
#ifndef RECURSIVE
            for(int i = 0; i < xDim; i++) {
                visited[i].resize(yDim);
                fill(visited[i].begin(), visited[i].end(), false);
            }
#endif
        }

        void readData() {
            for(int i = 0; i < matrix.size(); i++) {
                for(int j = 0; j < matrix[i].size(); j++) {
                    cin >> matrix[i][j];
                }
            }
        }

        void generateSequence(std::ostream& out) const {
            for(int i = 0; i < matrix.size(); i++) {
                for(int j = 0; j < matrix[i].size(); j++) {
                    out << matrix[i][j];
                    if (j != matrix[i].size() - 1) {
                        out << " ";
                    }
                }
                out << endl;
            }
        }

        inline friend std::ostream& operator<<(std::ostream& out, const FloodFill& obj) {
            obj.generateSequence(out);
            return out;
        }

        void floodFill(int x, int y, int color) {
#ifdef RECURSIVE
            runFloodFill(x, y, matrix[x][y], color);
#else
            bfsFloodFill(x, y, matrix[x][y], color);
#endif
        }
    private:
        vector<vector<int>> matrix;
#ifndef RECURSIVE
        vector<vector<bool>> visited;
#endif

        void runFloodFill(int x, int y, int prevColor, int color) {
            if (matrix[x][y] == prevColor) {
                matrix[x][y] = color;
                if (x + 1 < matrix.size()) {
                    runFloodFill(x + 1, y, prevColor, color);
                }
                if (x - 1 >= 0) {
                    runFloodFill(x - 1, y, prevColor, color);
                }
                if (y + 1 < matrix[x].size()) {
                    runFloodFill(x, y + 1, prevColor, color);
                }
                if (y - 1 >= 0) {
                    runFloodFill(x, y - 1, prevColor, color);
                }
            }
        }

#ifndef RECURSIVE 
        void bfsFloodFill(int x, int y, int prevColor, int color) {
            queue<pair<int, int>> _queue;
            _queue.push(make_pair(x, y));
            for (pair<int, int> it = _queue.front(); ! _queue.empty(); it = _queue.front()) {
                int i = it.first;
                int j = it.second;
                if (!visited[i][j] && matrix[i][j] == prevColor) {
                    matrix[i][j] = color;
                    if (i + 1 < matrix.size()) {
                        _queue.push(make_pair(i + 1, j));
                    }
                    if (i - 1 >= 0) {
                        _queue.push(make_pair(i - 1, j));
                    }
                    if (j + 1 < matrix[i].size()) {
                        _queue.push(make_pair(i, j + 1));
                    }
                    if (j - 1 >= 0) {
                        _queue.push(make_pair(i, j - 1));
                    }
                    visited[i][j] = true;
                }
                _queue.pop();
            }
        }
#endif
};

int main() {
    int amountOfCases = 0;
    cin >> amountOfCases;
    for (int i = 0; i < amountOfCases; i++) {
        int xDim = 0, yDim = 0;
        int xPosition, yPosition;
        int newColor;
        cin >> xDim >> yDim;
        cin >> xPosition >> yPosition;
        cin >> newColor;
        FloodFill floodFill(xDim, yDim);
        floodFill.readData();
#ifdef DEBUG
        cout << "############## Before Run ###############" << endl;
        cout << floodFill << endl;
#endif
        floodFill.floodFill(xPosition, yPosition, newColor);
#ifdef DEBUG
        cout << "############## After Run ###############" << endl;
#endif
        cout << floodFill << endl;
    }
}
