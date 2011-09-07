#!/bin/bash
#
# Counts how many files are in the directories passed
# as parameter. If not directories are passed it uses
# the current directory.

# If no arguments use only current directory
if [ $# -lt 1 ]
then
  dirs=.
else
  dirs=$*
fi

#Initialize file counter to 0
count=0

# for all the directories passed as argument
for dir in $dirs
do
  echo $dir:
  for file in $dir/*
  do
     echo "$count: $file"
     count=`expr $count + 1` 
  done
done

echo "$count files found"

