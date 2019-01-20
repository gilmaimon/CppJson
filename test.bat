mkdir build
cd build
cmake .. -G "Unix Makefiles"
make tests
tests
cd ..
echo "Done"