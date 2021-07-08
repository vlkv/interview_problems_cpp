/*
In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)


Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1


Constraints:

2 <= grid.length == grid[0].length <= 100
grid[i][j] == 0 or grid[i][j] == 1
*/
#include <unordered_set>
#include <vector>
#include <queue>
#include <gtest/gtest.h>
using namespace std;

using Grid = vector<vector<int>>;

struct Cell {
    int r;
    int c;
};

bool operator==(const Cell& a, const Cell& b) {
    return a.r == b.r && a.c == b.c;
}

struct CellHash {
    size_t operator()(const Cell& cell) const {
        return cell.r ^ cell.c;
    }
};

struct Item {
    Cell cell;
    int steps;
};

constexpr int SEA = 0;
constexpr int TARGET_LAND = 1;
constexpr int VISITED_LAND = 2;
constexpr int VISITED_SEA = 3;

class Solution {
    const vector<pair<int, int>> deltas = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0},
    };
public:
    int shortestBridge(vector<vector<int>>& grid) {
        auto landCell = findLand(grid);
        auto coastLine = findCoastLine(grid, landCell);
        queue<Item> q;
        for (const auto& c : coastLine) {
            q.push({c, 0});
        }

        while (!q.empty()) {
            const auto item = q.front();
            const auto& cell = item.cell;
            q.pop();

            if (grid[cell.r][cell.c] == VISITED_SEA) {
                continue;
            }
            grid[cell.r][cell.c] = VISITED_SEA;

            for (const auto& delta : deltas) {
                auto newRow = cell.r + delta.first;
                auto newCol = cell.c + delta.second;
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()) {
                    continue;
                }
                if (grid[newRow][newCol] == VISITED_SEA ||
                    grid[newRow][newCol] == VISITED_LAND) {
                    continue;
                }
                if (grid[newRow][newCol] == TARGET_LAND) {
                    return item.steps;
                }
                q.push({{newRow, newCol}, item.steps + 1});
            }
        }
        return -1;
    }
private:
    Cell findLand(const Grid& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    // Also, replaces all 1s in this island with 2s. To distinguish it from the other island.
    vector<Cell> findCoastLine(Grid& grid, const Cell& startCell) {
        unordered_set<Cell, CellHash> result;
        queue<Cell> q;
        q.push(startCell);
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();

            if (grid[cell.r][cell.c] == VISITED_LAND) {
                continue;
            }
            grid[cell.r][cell.c] = VISITED_LAND;

            for (const auto& delta : deltas) {
                auto newRow = cell.r + delta.first;
                auto newCol = cell.c + delta.second;
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()) {
                    continue;
                }
                if (grid[newRow][newCol] == VISITED_LAND) {
                    continue;
                }
                if (grid[newRow][newCol] == SEA) {
                    result.insert(cell);
                    continue;
                }
                q.push({newRow, newCol});
            }
        }
        return {result.begin(), result.end()};
    }
};

TEST(ShortestBridge, T1) {
    vector<vector<int>> grid = {
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 1, 1, 1, 0},
    };
    Solution s;
    ASSERT_EQ(s.shortestBridge(grid), 3);
}