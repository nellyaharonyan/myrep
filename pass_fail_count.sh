#!/usr/bin/env bash

files="$1 $2 $3 $4 $5"
passCount=0
failCount=0
for file in $files
do
        if [ -r $file ]
        then
                if grep -q PASS $file
                then
                        (( passCount++ ))
                        cp $file pass_$(basename $file)
                fi
                if grep -q FAIL $file
                then
                        (( failCount++ ))
                        cp $file fail_$(basename $file)
                fi
        else
                echo " $file is not readable "
        fi
done
echo "PASSES: $passCount "
echo "FAILS: $failCount "


