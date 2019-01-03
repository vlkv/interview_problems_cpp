#include "flood_fill.hpp"
#include <unordered_set>

CellsSet FloodFill::findLargestColorArea() {
	CellsSet result;

	for (int i = 0; i < _n; ++i) {
		for (int j = 0; j < _m; ++j) {
			Cell startCell {.x = i, .y = j};
			if (_visited.find(startCell) != _visited.end()) {
				continue;
			}

			std::unordered_set<Cell, CellHash, CellEqual> area = findColorArea(i, j);
			if (area.size() > result.size()) {
				result = area;
			}

			_visited.insert(startCell);
		}
	}

	return result;
}

CellsSet FloodFill::findColorArea(int startX, int startY) {
	CellsSet result;
	CellsSet cellsToVisit;
	Cell startCell {.x = startX, .y = startY};
	Color startColor = _data[startX][startY];
	cellsToVisit.insert(startCell);

	while (cellsToVisit.size() > 0) {
		auto cell = cellsToVisit.begin();
		cellsToVisit.erase(cell);
		_visited.insert(*cell);
		auto neighbours = cellNeighbours(*cell);
		for (auto c = neighbours.begin(); c != neighbours.end(); ++c) {
			Color cColor = _data[c->x][c->y];
			if (cColor != startColor) {
				continue;
			}
			if (_visited.find(*c) != _visited.end()) {
				continue;
			}
			cellsToVisit.insert(*c);
		}
		result.insert(*cell);
	}

	return result;
}

std::vector<Cell> FloodFill::cellNeighbours(const Cell& cell) {
	std::vector<Cell> result;
	if (cell.x > 0) {
		result.push_back(Cell {.x = cell.x - 1, .y = cell.y});
	}
	if (cell.x < _n - 1) {
		result.push_back(Cell {.x= cell.x + 1, .y = cell.y});
	}
	if (cell.y > 0) {
		result.push_back(Cell {.x = cell.x, .y = cell.y - 1});
	}
	if (cell.y < _m - 1) {
		result.push_back(Cell {.x = cell.x, .y = cell.y + 1});
	}
	return result;
}