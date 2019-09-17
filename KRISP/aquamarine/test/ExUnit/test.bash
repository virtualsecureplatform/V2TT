#!/bin/bash
for((i=0;i<5;i++))
do
    echo "MOV:Test "$((i+1))
    a=$(($RANDOM % 2**16))
    b=$(($RANDOM % 2**16))
    ./client 0 $a $b 0 1 0 0 0
    ./cloud 2
    res=(`./verify`)
    if [${res[0]} == 0];then
        echo MOV Test Failed
        exit
done
echo MOV Test Passed