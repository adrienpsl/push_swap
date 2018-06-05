#!/usr/bin/env bash
# make re
read mem

nm -u push_swap

function intro()
{
    echo "test de push_swap avec $1 numero 10 fois"
}

function border()
{
    a=`./checker $1  << EOF
EOF`
b=`./push_swap $1`

if [ "$a" != "OK" ];
	then
		echo "-------   $1"
		echo "check err : $a"
	fi

    if [ "$b" != "" ];
    then
		echo "-------   $1"
		echo "push err : $b"
	fi
}

function err_str ()
{

    a=`./checker $1`
    b=`./push_swap $1`



    if [ "$mem" = 1 ];
    then
        valgrind --log-fd=1 ./checker $1 | grep "definitely lost"
        valgrind --log-fd=1 ./push_swap $1 | grep "definitely lost"

    else

            if [ "$a" != "Error" ];
        then
            echo "-------   $1"
            echo "check err : $a"
        fi

        if [ "$b" != "Error" ];
        then
            echo "-------   $1"
            echo "push err : $b"
        fi
	fi


}

function err_arg ()
{
    a=`./checker $@`
    b=`./push_swap $@`


    if [ "$mem" = 1 ];
    then
        valgrind --log-fd=1 ./checker $1 | grep "definitely lost"
        valgrind --log-fd=1 ./push_swap $1 | grep "definitely lost"

    else

            if [ "$a" != "Error" ];
        then
            echo "-------   $@"
            echo "check err : $a"
        fi

        if [ "$b" != "Error" ];
        then
            echo "-------   $@"
            echo "push err : $b"
        fi


	fi
}

#    # que push push
#    nb="puts (1..10).to_a.shuffle.join(' ')"
#    ARG=`ruby -e "$nb"` ;
#    valgrind --log-fd=1 ./push_swap "$ARG"
#
#    # que check check
#    nb="puts (1..40000).to_a.shuffle.join(' ')"
#    ARG=`ruby -e "$nb"` ;
#    ./push_swap "$ARG"  | valgrind --log-fd=1 ./checker "$ARG"#


function check_mem()
{
    echo ========================================
    echo "test de push_swap avec $1 numero 30 fois"
    moy_ins=0;

    for tt in `seq 1 30`
    do
         nb="puts (1..$1).to_a.shuffle.join(' ')"
         ARG=`ruby -e "$nb"` ;

        if [ "$mem" = 1 ];
        then
            valgrind --log-fd=1 ./push_swap "$ARG" | grep "definitely lost"
            ./push_swap "$ARG"  | valgrind --log-fd=1 ./checker "$ARG" | grep "definitely lost"
        else
             is_ok=`./push_swap "$ARG"  | ./checker "$ARG"`
                if [ "$is_ok" != "OK" ];
                    then
                        echo pas ok
                fi

             nb_ins=`./push_swap "$ARG"  | wc -l`
             echo "$nb_ins";
#               if [[ $1 == ]]
#                then
#             fi
            ((moy_ins+=nb_ins))
	    fi
    done
    echo moyen---------------
#    echo "$moy_ins"
    ((moy_ins/=30))
#    echo "$moy_ins"


}



##*------------------------------------*\
##    simple error
#*------------------------------------*/
echo "bullshit test -------------------------------"
err_str a
err_str "a"

err_str a d
err_str "a b"

err_arg 444d
err_str "444d"

err_arg 444d
err_str "444d 55"

err_arg a111
err_str "a111 887"

err_arg -111-
err_str "-111-"

err_str "55 44 22 44"
err_arg 55 44 22 44

err_str "14 4 44 4564654646465"
err_arg 14 4 44 4564654646465

##*------------------------------------*\
##    LIMIT
##*------------------------------------*/
#border 2147483647
#border "2147483647"
#border -2147483648
#border "-2147483648"
#border 0
#border "0"
#border -0
#border "-0"
#valgrind --log-fd=1 ./checker 0 | grep "definitely lost"
#valgrind --log-fd=1 ./push_swap 0 | grep "definitely lost"
#
#valgrind --log-fd=1 ./checker  | grep "definitely lost"
#valgrind --log-fd=1 ./push_swap | grep "definitely lost"



check_mem 1
check_mem 2
check_mem 3
check_mem 12
check_mem 50
check_mem 100
check_mem 500
check_mem 1000
check_mem 5000
check_mem 40000

#leaks_check



#echo "$b"

# while true; do; ARG=`ruby -e "puts (-100..10000).to_a.shuffle.join(' ')"` | ./push_swap $ARG | ./checker $ARG ; done
# while 1; do; leaks_push checker | grep "Process" | grep "leaks_push"; done


