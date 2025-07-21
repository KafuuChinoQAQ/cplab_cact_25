if [ -d "build" ]; then
    # 保留 mini-llvm 文件夹，删除其他内容
    find build -mindepth 1 -maxdepth 1 ! -name "mini-llvm" -exec rm -rf {} +
else
    mkdir -p build
fi && cd build && cmake .. && make -j