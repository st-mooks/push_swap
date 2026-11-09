rm -f ARGS.txt push_swap
if [ "$#" -ne 1 ]
then
    echo "To use the generator please enter an int\ne.g:\n\t./gen_args.sh 10\nOR\n\t./run_test.sh 10";
else
    shuf -i 0-$1 -o ARGS.txt
    echo "Successfully generated $1 args and saved into ARGS.txt";
fi
cc *.c -L./libft -lft -o push_swap -g
./push_swap $(cat ARGS.txt)
rm -f ARGS.txt push_swap