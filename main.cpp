#include<bits/stdc++.h>
//#define DEBUG

using namespace std;

class FloodFill {
    public:
        FloodFill(int xDim, int yDim) : matrix(xDim) {
            for(int i = 0; i < xDim; i++) {
                matrix[i].resize(yDim);
            }
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
            runFloodFill(x, y, matrix[x][y], color);
        }
    private:
        vector<vector<int>> matrix;

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
