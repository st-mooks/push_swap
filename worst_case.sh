rm -f WORST_CASE.txt
i="$1"
if [ "$#" -eq 0 ]
then
	echo "Please enter the number of args to generate"
else
	while [ $i -ge 1 ]
		do
			echo "$i" >> WORST_CASE.txt
			i=$(( $i - 1 ))
	done
fi