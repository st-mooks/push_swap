i=1
while [ $i -le 500 ]
do
	echo "$i" >> WORST_CASE.txt
	$i = $(( $i + 1 ))
done