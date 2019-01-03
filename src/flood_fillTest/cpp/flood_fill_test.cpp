#include <gtest/gtest.h>
#include "flood_fill.hpp"

TEST(FloodFillProblemSolverTest, Test1) {

	std::vector<std::vector<Color>> data {
		{ 2, 2, 3 },
	    { 4, 1, 3 },
	    { 4, 1, 1 },
	    { 4, 2, 1 },
	};
	
	FloodFill ff(data);
	auto res = ff.findLargestColorArea();
    EXPECT_EQ(res.size(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}