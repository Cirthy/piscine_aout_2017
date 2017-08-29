#!/bin/sh

nbip=$(ifconfig | grep 'inet ' | cut -d' ' -f2 | tail -n-1 | wc -l)
if [ $nbip -eq 0 ]
then
    echo "je suis perdu\n"
else
    ifconfig | grep 'inet ' | cut -d' ' -f2 | tail -n-1
fi