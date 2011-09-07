#!/bin/sh
# Prints "Hello world" every 5 secs
# This shell script shows how to use while and how to
# arithmetic operations in a shell script.
#
PAUSE=5
count=0
while [ "1" ]
do
	echo "Hello world after" $count seconds 
	sleep $PAUSE
	count=`expr $count + $PAUSE`
done

