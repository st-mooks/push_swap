#!/bin/zsh
mkdir -p test_results
DIR=./test_results/
rm -f push_swap ${DIR}ARGS.txt ${DIR}stdout.txt ${DIR}stderr.txt ${DIR}valgrind.txt
if [ "$#" -eq 0 ]
then
    echo "To use the generator please enter number of ints to generate, followed by optional flags\ne.g:\n\t./run_test.sh 10 --bench --simple\nOR\n\t./run_test.sh 10"
    exit
else
    shuf -i 0-$1 -o ${DIR}ARGS.txt
    echo "Successfully generated $1 args."
fi
make -s
make bonus -s
make clean -s
chmod +x checker
chmod +x checker_linux
if [ -z "$2" ] || [ "$2" = "--bench" ]
then
	./push_swap $(cat ${DIR}ARGS.txt) 1>${DIR}stdout.txt 2>${DIR}stderr.txt
    valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./push_swap --bench $(cat ${DIR}ARGS.txt) 1>temp 2>${DIR}valgrind.txt
elif [ -z "$3" ] || [ "$3" = "--bench" ]
then
    ./push_swap $2 $(cat ${DIR}ARGS.txt) 1>${DIR}stdout.txt 2>${DIR}stderr.txt
    valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./push_swap --bench $2 $(cat ${DIR}ARGS.txt) 1>temp 2>${DIR}valgrind.txt
else
	echo "Invalid inputs."
    exit
fi
echo "Bonus checker result:"
./checker $(cat ./test_results/ARGS.txt) < ./test_results/stdout.txt
echo "checker_linux results:"
./checker_linux $(cat ./test_results/ARGS.txt) < ./test_results/stdout.txt
echo "Test complete. Test results and parameters saved into ./test_results/"
rm -f push_swap temp checker