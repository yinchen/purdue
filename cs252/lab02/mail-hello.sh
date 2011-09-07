#!/bin/sh
#
# This script builds a simple message and mails it to 
# yourself
#
echo "Hello $USER!!" > tmp-message
echo >> tmp-message
echo "Today is" `date`  >> tmp-message
echo >> tmp-message
echo "Sincerely," >> tmp-message
echo "     Myself" >> tmp-message
/usr/bin/mailx -s "mail-hello" $USER < tmp-message 
echo "Message sent."

