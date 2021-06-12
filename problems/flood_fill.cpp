#include "flood_fill.hpp"
#include <unordered_set>
#include <queue>

CellsSet FloodFill::findLargestColorArea() {
	CellsSet result;

	for (int col = 0; col < _cols; ++col) {
		for (int row = 0; row < _rows; ++row) {
			Cell cell {.col = col, .row = row};
			if (_visited.find(cell) != _visited.end()) {
				continue;
			}

			CellsSet area = findColorArea(cell);
			if (area.size() > result.size()) {
				result = area;
			}
		}
	}

	return result;
}

CellsSet FloodFill::findColorArea(const Cell& startCell) {
	CellsSet result;
	std::queue<Cell> queue;
	Color startColor = _data[startCell.row][startCell.col];
	queue.push(startCell);

	while (!queue.empty()) {
		auto cell = queue.front();
		queue.pop();

		if (_visited.count(cell) > 0) {
			continue;
		}
		_visited.insert(cell);
		result.insert(cell);

		auto neighbours = cellNeighbours(cell);
		for (auto c = neighbours.begin(); c != neighbours.end(); ++c) {
			Color cColor = _data[c->row][c->col];
			if (cColor != startColor) {
				continue;
			}
			if (_visited.count(*c) > 0) {
				continue;
			}
			queue.push(*c);
		}

	}

	return result;
}

std::vector<Cell> FloodFill::cellNeighbours(const Cell& cell) {
	std::vector<Cell> result;
	if (cell.col > 0) {
		result.push_back(Cell {.col = cell.col - 1, .row = cell.row});
	}
	if (cell.col < _cols - 1) {
		result.push_back(Cell {.col= cell.col + 1, .row = cell.row});
	}
	if (cell.row > 0) {
		result.push_back(Cell {.col = cell.col, .row = cell.row - 1});
	}
	if (cell.row < _rows - 1) {
		result.push_back(Cell {.col = cell.col, .row = cell.row + 1});
	}
	return result;
}