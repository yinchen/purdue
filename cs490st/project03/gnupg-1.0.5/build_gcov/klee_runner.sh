#!/bin/bash
FILES=../build/klee-out-0/*.ktest

for f in $FILES
do
  echo "Processing $f file..."
  klee-replay.cde --create-files-only $f
  g10/gpg A
done
