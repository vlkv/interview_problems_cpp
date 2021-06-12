* Install gtest sources
  - `sudo apt-get install libgtest-dev`
* Build gtest
  - `sudo apt-get install cmake` # install cmake
  - `cd /usr/src/gtest`
  - `sudo cmake CMakeLists.txt`
  - `sudo make`
* Copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
    `sudo cp *.a /usr/lib`

* In the root of this project:
  - `cmake ./CMakeLists.txt`
  - `make`
  - `./test/run_tests --gtest_filter=QuickSortTest.`
