echo "This is the content for file a.\\nhello\\nhello" > a
touch b c d e f g h i
echo test 1 - counts lines of folder
valgrind ./pipex a "cat" "wc -l" b
