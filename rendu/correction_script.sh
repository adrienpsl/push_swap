# make re

function err ()
{
	a=`./checker $1`
	if [ "$a" = "Error" ];
		then
		true
	else
		echo "-------     $1" 
		echo "$a"
	fi
}

function err2 ()
{
	if [ "$1" = "Error" ];
		then
		true
	else
		echo "-------     $1" 
	fi
}

err a
err " a"

err 444d
err "444d 55"

err a111
err "a111 887"

err2 -111-
err "-111-"

a=`./checker 55 44 44` ; err2 $a
err "55 44 22 44"

err "14 4 44 4564654646465"
a=`./checker 14 4 44 4564654646465` ; err2 $a

./checker

# while true; do; ARG=`ruby -e "puts (-100..10000).to_a.shuffle.join(' ')"` | ./push_swap $ARG | ./checker $ARG ; done
# while 1; do; leaks checker | grep "Process" | grep "leaks"; done


