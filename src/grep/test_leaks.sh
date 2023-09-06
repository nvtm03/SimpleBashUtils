leaks -atExit -- ./s21_grep

echo "test flag e"
echo "test: -e hello -e ok  test.txt"
leaks -atExit -- ./s21_grep -e hello -e ok  test.txt

echo "test: -e hello -e ok  test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -e hello -e ok  test.txt test_1_grep.txt

echo "test: hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep hello test.txt test_1_grep.txt

echo "test: hello test.txt"
leaks -atExit -- ./s21_grep hello test.txt


echo
echo "test flag i"
echo "test: -i Hello test.txt"
leaks -atExit -- ./s21_grep -i hello test.txt

echo "test: -i Hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -i Hello test.txt test_1_grep.txt


echo
echo "test flag c"
echo "test: -c hello test.txt"
leaks -atExit -- ./s21_grep -c hello test.txt

echo "test: -c hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -c hello test.txt test_1_grep.txt


echo
echo "test flag l"
echo "test: -l hello test.txt"
leaks -atExit -- ./s21_grep -l hello test.txt

echo "test: -l hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -l hello test.txt test_1_grep.txt


echo
echo "test flag n"
echo "test: -n hello test.txt"
leaks -atExit -- ./s21_grep -n hello test.txt

echo "test: -n hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -n hello test.txt test_1_grep.txt


echo
echo "test flag h"
echo "test: -h hello test.txt"
leaks -atExit -- ./s21_grep -h hello test.txt

echo "test: -h hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -h hello test.txt test_1_grep.txt


echo
echo "test flag s"
echo "test: -s hello test.txt"
leaks -atExit -- ./s21_grep -s hello test.txt

echo "test: -s hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -s hello test.txt test_1_grep.txt


echo
echo "test flag o"
echo "test: -o hello test.txt"
leaks -atExit -- ./s21_grep -o hello test.txt

echo "test: -o hello test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -o hello test.txt test_1_grep.txt


echo
echo "test flag f"
echo "test: -f test_flag_f.txt test.txt"
leaks -atExit -- ./s21_grep -f test_flag_f.txt test.txt

echo "test: -f test_flag_f.txt test.txt test_1_grep.txt"
leaks -atExit -- ./s21_grep -f test_flag_f.txt test.txt test_1_grep.txt