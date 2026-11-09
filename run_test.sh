rm -f ARGS.txt push_swap
if [ "$#" -eq 0 ]
then
    echo "To use the generator please enter an int\ne.g:\n\t./run_test.sh 10 --bench --simple\nOR\n\t./run_test.sh 10";
else
    shuf -i 0-$1 -o ARGS.txt
    echo "Successfully generated $1 args and saved into ARGS.txt";
fi
cc *.c -L./libft -lft -o push_swap -g
if [ -z "$2" ]
then
	./push_swap $(cat ARGS.txt)
elif [ -z "$3" ]
then
./push_swap $2 $(cat ARGS.txt)
else
	./push_swap $2 $3 $(cat ARGS.txt)
fi
rm -f ARGS.txt push_swap