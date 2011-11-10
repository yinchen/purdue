#!/bin/bash

ARRAYSCOUNT=10
count=1
innercount=1
echo "  .data" > arrays.asm
while [ "$count" -le $ARRAYSCOUNT ]  
do
  size=0
  while [ $size -lt 5 ]
  do
    size=$RANDOM
    let "size %= 100"
  done
  echo "size"$count": .word "$size
  kth=0
  while [ $kth -lt 2 ]
  do
    kth=$RANDOM
    let "kth %= size"
  done
  echo "k"$count": .word "$kth
  innercount=1
  while [ "$innercount" -le $size ]     
  do
    element=$RANDOM
    let "element %= 1000"
    if [ $innercount == 1 ];
    then
        elements=$element
    else
        elements=$elements","$element
    fi
    let "innercount += 1"
  done
  echo "array"$count"a: .word "$elements
  echo "array"$count"b: .word "$elements
  let "count += 1"  # Increment count.
done >> arrays.asm
