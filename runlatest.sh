[ -d build ] || mkdir build
cd build
cmake ..
make
./glfw_hello
