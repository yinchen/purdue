#!/bin/bash

if [ $# -ne 4 ]
then
	echo "Usage: backupd.sh dir backupdir interval-secs max-backups"
	exit 65
fi

ls -lR $1 > ls-lR.last

DATE=$(date +"%Y-%m-%d-%H-%M-%S")
cp -r $1 $2/$DATE

COUNT=1

while [ 1 ];
do
	sleep $3
	 
	ls -lR $1 > ls-lR.new
	diff ls-lR.new ls-lR.last
	
	if [ $? -eq 1 ]
	then
	    DATE=$(date +"%Y-%m-%d-%H-%M-%S")
		cp -r $1 $2/$DATE
		
		COUNT=$(expr $COUNT + 1)
		
		mv ls-lR.new ls-lR.last
	fi
	
	if [ $COUNT -gt $4 ]
	then
	    rm -R $2/$(ls -lt $2 | grep '^d' | tail -1  | tr " " "\n" | tail -1)
	    COUNT=$(expr $COUNT - 1)
	fi
done

