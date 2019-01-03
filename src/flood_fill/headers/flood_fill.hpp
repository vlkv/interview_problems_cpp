#ifndef FLOOD_FILL_HPP__
#define FLOOD_FILL_HPP__

#include <vector>
#include <unordered_set>


typedef int Color;

struct Cell {
	int col;
	int row;
};

struct CellHash {
	std::size_t operator()(const Cell& cell) const
	{
 		return std::hash<int>()(cell.col) ^
	        (std::hash<int>()(cell.row) << 1);
	}
};
 
struct CellEqual {
	bool operator()(const Cell& lhs, const Cell& rhs) const
	{
		return lhs.col == rhs.col && lhs.row == rhs.row;
	}
};

typedef std::unordered_set<Cell, CellHash, CellEqual> CellsSet;

class FloodFill {
private:
	std::vector<std::vector<Color>> _data;
	CellsSet _visited;
	int _rows;
	int _cols;

public:
	FloodFill(const std::vector<std::vector<Color>>& data) :
		_data(data) {
			_rows = data.size();
			_cols = data[0].size();
	}

	CellsSet findLargestColorArea();

private:
	CellsSet findColorArea(const Cell& startCell);
	std::vector<Cell> cellNeighbours(const Cell& cell);
};

#endif