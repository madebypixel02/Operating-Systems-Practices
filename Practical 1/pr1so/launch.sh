#!/bin/bash

case $# in
	1)
		SECONDS=3
		;;
	
	2)	SECONDS=$2
		;;

	*)
		echo Wrong parameters
		echo Usage: $0 num_processes [time]
		exit
		;;
esac

F1=/tmp/$$.1
F2=/tmp/$$.2

trap '' SIGUSR1
trap '' SIGTERM

for i in `seq 1 $1`
do
	./count1  >> $F1 &
	./count2  >> $F2 &
done

sleep 1

kill -USR1 -$$ # Go
sleep $SECONDS
kill -TERM -$$ # Stop

wait

cat $F1 $F2

rm -f $F1 $F2
