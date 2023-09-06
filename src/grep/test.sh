echo "test flag e"
echo "test: -e hello -e ok  test.txt"
./s21_grep -e hello -e ok  test.txt > s21_grep.txt
grep -e hello -e ok test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -e hello -e ok  test.txt test_1_grep.txt"
./s21_grep -e hello -e ok  test.txt test_1_grep.txt > s21_grep.txt
grep -e hello -e ok test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: hello test.txt test_1_grep.txt"
./s21_grep hello test.txt test_1_grep.txt > s21_grep.txt
grep hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: hello test.txt"
./s21_grep hello test.txt > s21_grep.txt
grep hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -ehello -eok  test.txt"
./s21_grep -ehello -eok  test.txt > s21_grep.txt
grep -ehello -eok test.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag i"
echo "test: -i Hello test.txt"
./s21_grep -i hello test.txt > s21_grep.txt
grep -i hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -i Hello test.txt test_1_grep.txt"
./s21_grep -i Hello test.txt test_1_grep.txt > s21_grep.txt
grep -i Hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag c"
echo "test: -c hello test.txt"
./s21_grep -c hello test.txt > s21_grep.txt
grep -c hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -c hello test.txt test_1_grep.txt"
./s21_grep -c hello test.txt test_1_grep.txt > s21_grep.txt
grep -c hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag l"
echo "test: -l hello test.txt"
./s21_grep -l hello test.txt > s21_grep.txt
grep -l hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -l hello test.txt test_1_grep.txt"
./s21_grep -l hello test.txt test_1_grep.txt > s21_grep.txt
grep -l hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag n"
echo "test: -n hello test.txt"
./s21_grep -n hello test.txt > s21_grep.txt
grep -n hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -n hello test.txt test_1_grep.txt"
./s21_grep -n hello test.txt test_1_grep.txt > s21_grep.txt
grep -n hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag h"
echo "test: -h hello test.txt"
./s21_grep -h hello test.txt > s21_grep.txt
grep -h hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -h hello test.txt test_1_grep.txt"
./s21_grep -h hello test.txt test_1_grep.txt > s21_grep.txt
grep -h hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag s"
echo "test: -s hello test.txt"
./s21_grep -s hello test.txt > s21_grep.txt
grep -s hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -s hello test.txt test_1_grep.txt"
./s21_grep -s hello test.txt test_1_grep.txt > s21_grep.txt
grep -s hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag o"
echo "test: -o hello test.txt"
./s21_grep -o hello test.txt > s21_grep.txt
grep -o hello test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -o hello test.txt test_1_grep.txt"
./s21_grep -o hello test.txt test_1_grep.txt > s21_grep.txt
grep -o hello test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt


echo
echo "test flag f"
echo "test: -f test_flag_f.txt test.txt"
./s21_grep -f test_flag_f.txt test.txt > s21_grep.txt
grep -f test_flag_f.txt test.txt > grep.txt
diff -q s21_grep.txt grep.txt

echo "test: -f test_flag_f.txt test.txt test_1_grep.txt"
./s21_grep -f test_flag_f.txt test.txt test_1_grep.txt > s21_grep.txt
grep -f test_flag_f.txt test.txt test_1_grep.txt > grep.txt
diff -q s21_grep.txt grep.txt