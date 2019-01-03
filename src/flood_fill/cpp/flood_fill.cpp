#include "flood_fill.hpp"
#include <unordered_set>

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

			_visited.insert(cell);
		}
	}

	return result;
}

CellsSet FloodFill::findColorArea(const Cell& startCell) {
	CellsSet result;
	CellsSet cellsToVisit;
	Color startColor = _data[startCell.row][startCell.col];
	cellsToVisit.insert(startCell);

	while (cellsToVisit.size() > 0) {
		auto cell = cellsToVisit.begin();
		cellsToVisit.erase(cell);
		_visited.insert(*cell);
		auto neighbours = cellNeighbours(*cell);
		for (auto c = neighbours.begin(); c != neighbours.end(); ++c) {
			Color cColor = _data[c->row][c->col];
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