echo -e "This is the content for file1.\\nola\\nola" > a
touch b c d e f g h i j k l m n
echo testb - sort reverse
valgrind --leak-check=full ./pipex a "sort -r" " uniq -c" b
echo \\n
echo testc - Lines with file
valgrind --leak-check=full ./pipex a "grep file" "wc -w" c
echo \\n
echo testd - Counts files folder
valgrind --leak-check=full ./pipex a "ls -l" "wc -l" d
echo \\n
echo teste - Counts lines
valgrind --leak-check=full ./pipex a "wc -l" "cat" e
echo \\n
echo testf - Unique lines + sort
valgrind --leak-check=full ./pipex a "sort" "uniq -c" f
echo \\n
echo testg - Number bytes
valgrind --leak-check=full ./pipex a "cat" "wc -c" g
echo \\n
echo testh - Lines with error
valgrind --leak-check=full ./pipex a "grep 'error'" "wc -l" h
echo \\n
echo testi - Sort a
valgrind --leak-check=full ./pipex a "sort" "cat" i
echo \\n
echo testj - too few arguments
valgrind --leak-check=full ./pipex a "find -name .txt" "cat"
echo \\n
echo testk - too many arguments
valgrind --leak-check=full ./pipex a "find -name .txt" "cat" k "sort"
echo \\n
echo testl - empty strings/arguments
valgrind --leak-check=full ./pipex "" "" "" ""
echo \\n
echo testm - non existing file
valgrind --leak-check=full ./pipex z "cat" "wc -c" m
echo \\n
echo testn - invalid command
valgrind --leak-check=full ./pipex a "invalid command" "wc -c" m
echo \\n

