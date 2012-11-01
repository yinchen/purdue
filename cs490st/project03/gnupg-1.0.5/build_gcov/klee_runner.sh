#!/bin/bash
FILES=../build/klee-out-0/*.ktest

for f in $FILES
do
  echo "Processing $f file..."
  klee-replay.cde g10/gpg $f
done
