#include "flood_fill.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(FloodFillTest, Test1) {

	std::vector<std::vector<Color>> data {
		{ 2, 2, 3 },
		{ 4, 1, 3 },
		{ 4, 1, 1 },
		{ 4, 2, 1 },
	};
	
	FloodFill ff(data);
	auto res = ff.findLargestColorArea();
	std::cout << "Result is" << std::endl;
	for (auto it = res.begin(); it != res.end(); ++it) {
		std::cout << "row=" << it->row << ", col=" << it->col << std::endl;	
	}
	
    EXPECT_EQ(res.size(), 4);
    Color color = data[res.begin()->row][res.begin()->col];
    EXPECT_EQ(1, color);
	EXPECT_NE(res.find(Cell{.col=1, .row=1}), res.end());
	EXPECT_NE(res.find(Cell{.col=1, .row=2}), res.end());
	EXPECT_NE(res.find(Cell{.col=2, .row=2}), res.end());
	EXPECT_NE(res.find(Cell{.col=2, .row=3}), res.end());
}
