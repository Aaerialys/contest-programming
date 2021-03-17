# install gcc https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j
set -e
g++ main.cpp -o code -std=c++1z
g++ jen.cpp -o gen -std=c++1z
g++ reference.cpp -o brute -std=c++1z
#g++ checker.cpp -o checker
for((i = 1; ; ++i)); do
    ./gen $i > input_file.txt
    ./code < input_file.txt > myAnswer.txt
    #./checker > checker_log.txt
    ./brute < input_file.txt > correctAnswer.txt
    diff -Z myAnswer.txt correctAnswer.txt > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file.txt
echo "Your answer is:"
cat myAnswer.txt
echo "Correct answer is:"
cat correctAnswer.txt
read 