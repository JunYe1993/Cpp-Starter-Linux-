#!/bin/bash

FILES=000*/main.cpp
for f in $FILES; do
    cat $f | grep -v main
    content=""
    content=$(cat $f | grep -v main)
    echo $f
    echo
    echo $content
    echo ----------------------
done