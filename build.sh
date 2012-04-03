DIR=build &&
#rm -fr ./${DIR} &&
#mkdir -p ${DIR} &&
cd ${DIR} &&
#export CC=/usr/bin/clang
export CC=/usr/bin/colorgcc
cmake -D CMAKE_BUILD_TYPE=Debug .. &&
make
