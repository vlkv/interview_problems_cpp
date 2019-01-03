#include "flood_fill.hpp"
#include <gtest/gtest.h>
#include <iostream>

TEST(FloodFillProblemSolverTest, Test1) {

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
    Color c = data[res.begin()->row][res.begin()->col];
    EXPECT_EQ(1, c);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}