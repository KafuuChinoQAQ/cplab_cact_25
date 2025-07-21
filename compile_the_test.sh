# 用法: ./compile_the_test.sh file_name
file_name=./test/$1
./build/compiler $file_name
./build/mini-llvm/rv64i ./test.ll