#!/usr/bin/env bash

file=$1
n=0 # Array lenght

# Create and initialize an array with input file lines
getArray() {
        array=() # Create array
        if [ -f $file ]
        then    
                if [ -r $file ]
                then    
                        while IFS= read -r line # Read a line
                        do      
                                array+=("$line") # Add line to the array
                                (( n++ ))
                        done < "$1"
                else    
                        echo "File $file is not readable"
                fi
        else    
                echo "File $file does not exist"
        fi
}

# Sort the array lexicographically
bubleSort() {
for (( i = 0; i < $n ; i++ ))
do
        for (( j = $i; j < $n; j++ ))
        do
                if [ "${array[$i]}" \> "${array[$j]}"  ]
                then
                        t=${array[$i]}
                        array[$i]=${array[$j]}
                        array[$j]=$t
                fi
        done
done
}

getArray $file
bubleSort
# Write array elements to file linle by line
printf "%s\n" "${array[@]}" > output.txt
