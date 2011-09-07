#!/bin/sh
#
# This shell script prints hello to all the friends you
# pass as parameter
#

if [ $# -le 1 ] 
then
  echo
  echo "$0 needs at least one argument"
  echo "  Eg."
  echo "     $0 Mickey Donald Daisy"
fi

for friend in $* 
do
  echo "Hello $friend"
done

