# 如果已经存在test114文件，则删除它
if [ -f test114 ]; then
    rm test114
fi

# 编译 LLVM IR 文件为可执行文件
clang test.ll mylib.o -o test114

# 运行可执行文件
./test114
EXIT_CODE=$?

# 输出返回值
echo "Main function returned: $EXIT_CODE"

exit 1
