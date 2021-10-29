#!/bin/bash

if [ $# -lt 1 ]
then
    echo -n "Filename: "
    read filename
else
    filename=$1
fi

cat main.cpp >> archive/$filename