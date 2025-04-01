[Console]::OutputEncoding = [System.Text.Encoding]::UTF8 # 设置输出编码为 UTF-8 同时该文件应该保存为 UTF-8-bom 编码格式

# 检查本地 grammar 文件夹是否存在，如果不存在则报错
if (-Not (Test-Path -Path "E:\Homework\cplab\cact\grammar")) {
    Write-Host "错误：本地 grammar 文件夹不存在，请检查路径。"
    exit 1
} else {
    # 如果 grammar 文件夹存在，删除除了.g4以外的所有文件和子文件夹
    Get-ChildItem -Path "E:\Homework\cplab\cact\grammar" -Recurse | Where-Object { $_.Extension -ne ".g4" } | Remove-Item -Force -Recurse
    Write-Host "已删除 grammar 文件夹中所有非 .g4 文件和子文件夹"
}

Set-Location -Path "E:\Homework\cplab\cact\grammar" # 切换到 grammar 文件夹
# 对于grammar文件夹下的所有.g4文件 执行antlr编译命令
# 使用deps文件夹下的antlr-4.13.1-complete.jar文件进行编译
# -Dlanguage=Cpp 指定生成C++代码
# -package cactparser 指定生成的代码包名为cplab_parser 即包裹在cplab_parser命名空间下
# -visitor 生成访问器模式的代码
# -no-listener 不生成监听器模式的代码
Get-ChildItem -Path "E:\Homework\cplab\cact\grammar" -Filter "*.g4" | ForEach-Object {
    java -jar ../deps/antlr-4.13.1-complete.jar -Dlanguage=Cpp -package cplab_parser $_.FullName -visitor -no-listener
}
Write-Host "ANTLR 代码生成完成"

Set-Location -Path ".." # 切换回上级目录

# 检查远程文件夹grammar和src是否存在并删除
ssh compiler04@124.16.71.60 'if [ -d "/home/compiler04/cact/grammar" ]; then rm -rf "/home/compiler04/cact/grammar"; fi'
ssh compiler04@124.16.71.60 'if [ -d "/home/compiler04/cact/src" ]; then rm -rf "/home/compiler04/cact/src"; fi'
Write-Host "远程文件夹已删除"

# 执行 SCP 命令上传文件夹grammar和src
scp -r "E:\Homework\cplab\cact\grammar" compiler04@124.16.71.60:"/home/compiler04/cact/grammar"
scp -r "E:\Homework\cplab\cact\src" compiler04@124.16.71.60:"/home/compiler04/cact/src"
Write-Host "文件上传完成"

# 在远程服务器上执行编译
ssh compiler04@124.16.71.60 'cd /home/compiler04/cact && if [ -d "build" ]; then rm -rf build; fi && mkdir -p build && cd build && cmake .. && make -j'
Write-Host "远程编译完成"

# 在远程服务器上运行可执行文件compiler
ssh compiler04@124.16.71.60 'cd /home/compiler04/cact/build && ./compiler'