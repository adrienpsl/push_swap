#!/usr/bin/env bash
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

function leaks_push ()
{
    echo; echo;
    echo ========================================
    echo "test de push_swap avec $1 numero 10 fois"
    for tt in `seq 1 10`

    do
        nb="puts (1..$1).to_a.shuffle.join(' ')"
        ARG=`ruby -e "$nb"` ;
#        echo $ARG
        valgrind --log-fd=1 ./push_swap "$ARG" | grep "definitely lost"
    done


}

function leaks_check ()
{
    echo; echo;
    echo ========================================
    echo "test de push_swap avec $1 numero 10 fois"
    for tt in `seq 1 10`

    do
        nb="puts (1..$1).to_a.shuffle.join(' ')"
        ARG=`ruby -e "$nb"` ;
#        echo $ARG
        valgrind --log-fd=1 ./checker "$ARG" | grep "definitely lost"
    done


}

err a
err " a"

err 444d
err "444d 55"

err a111
err "a111 887"

err -111-
err "-111-"


a=`./checker 55 44 44` ; err2 "$a"
err "55 44 22 44"

err "14 4 44 4564654646465"
a=`./checker 14 4 44 4564654646465` ; err2 "$a"

./checker
echo -e "\n" | ./checker 2147483647
./checker "-2147483648"


./checker 2147483647  << EOF
EOF



#leaks_push 0
#leaks_push 1
#leaks_push 2
#leaks_push 3
#leaks_push 15
#leaks_push 30
#leaks_push 100
#leaks_push 500
#leaks_push 10000

#leaks_check



#echo "$b"

# while true; do; ARG=`ruby -e "puts (-100..10000).to_a.shuffle.join(' ')"` | ./push_swap $ARG | ./checker $ARG ; done
# while 1; do; leaks_push checker | grep "Process" | grep "leaks_push"; done


