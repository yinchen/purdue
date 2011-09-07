#!/bin/sh
#
# This message prints the current temperature by going to
# The weather channel homesite and filtering the string "current temp:"
#
ZIP=47906
URL_WEATHER="http://www.weather.com/weather/local/$ZIP"
lynx -source "$URL_WEATHER" | awk ' /temp=/ { split($0,a,"&"); print a[4]}'
