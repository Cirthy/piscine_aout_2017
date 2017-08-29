#!/bin/sh
touch -A -01 bomb.txt
date -r bomb.txt +%s | sed 's/$/n/' | tr 'n' '\n' | cat -e