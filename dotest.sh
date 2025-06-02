# 尝试删除已有的syntax_tree.txt文件
rm -f ./syntax_tree.txt

# 如果没有参数，遍历所有文件
if [ $# -eq 0 ]; then
  for file in ./test/samples_lex_and_syntax/*; do
    ./build/compiler "$file"
  done
# 如果有一个参数，取第 n+1 个文件
elif [ $# -eq 1 ]; then
  n=$1
  files=(./test/samples_lex_and_syntax/*)
  if [ "$n" -ge 0 ] && [ "$n" -lt "${#files[@]}" ]; then
    ./build/compiler "${files[$n]}"
  else
    echo "参数超出文件数量范围"
    exit 1
  fi
else
  echo "用法: $0 [n]"
  exit 1
fi