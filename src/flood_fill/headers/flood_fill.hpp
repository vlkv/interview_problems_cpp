#ifndef FLOOD_FILL_HPP__
#define FLOOD_FILL_HPP__

#include <vector>
#include <unordered_set>


typedef int Color;

struct Cell {
	int x;
	int y;
};

struct CellHash {
	std::size_t operator()(const Cell& cell) const
	{
 		return std::hash<int>()(cell.x) ^
	        (std::hash<int>()(cell.y) << 1);
	}
};
 
struct CellEqual {
	bool operator()(const Cell& lhs, const Cell& rhs) const
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

typedef std::unordered_set<Cell, CellHash, CellEqual> CellsSet;

class FloodFill {
private:
	std::vector<std::vector<Color>> _data;
	CellsSet _visited;
	int _m;
	int _n;

public:
	FloodFill(const std::vector<std::vector<Color>>& data) :
		_data(data) {
			_n = data[0].size();
			_m = data.size();
	}

	CellsSet findLargestColorArea();

private:
	CellsSet findColorArea(int startX, int startY);
	std::vector<Cell> cellNeighbours(const Cell& cell);
};

#endif