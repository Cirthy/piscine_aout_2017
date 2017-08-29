#!/bin/sh

cat $1 | grep -i '^nicolas	bauer' | tr '	' '\n' | grep '-' | grep -v '@'