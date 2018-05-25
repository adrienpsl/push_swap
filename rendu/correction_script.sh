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

err a
err " a"

err 444d
err "444d 55"

err a111
err "a111 887"

# err 44 22 44
err "55 44 22 44"

# err 14165413131; 
