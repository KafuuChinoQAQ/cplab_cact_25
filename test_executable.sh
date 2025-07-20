#!/bin/b,sh

# 运行可执行文件
./test114
EXIT_CODE=$?

# 输出返回值
echo "Main function returned: $EXIT_CODE"

# 验证预期返回值（根据您的 LLVM IR，应该返回 75）
EXPECTED=75
if [ $EXIT_CODE -eq $EXPECTED ]; then
    echo "✓ Test PASSED: Expected $EXPECTED, got $EXIT_CODE"
    exit 0
else
    echo "✗ Test FAILED: Expected $EXPECTED, got $EXIT_CODE"
    exit 1
fi