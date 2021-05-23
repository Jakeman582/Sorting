#!/bin/bash

# Get the project root
full_path=$(realpath $0)
dir_path=$(dirname $full_path)
project_path=$(dirname $dir_path)

# Grab the sort executable
exe="$project_path/sort"

# Grab every input data file
data_dir="$project_path/input"
files=($data_dir/*)

# Set up column headers in an output file
output_file="$project_path/profiling/timings.txt"
echo "number    CPU_Time" > $output_file

# Run through each data file and time each execution
for ((i=0; i<${#files[@]}; i++)); do
    # Get the file name
    input=${files[$i]}

    # Calculate the CPU time
    cpu_time=`(time $exe $input) 2>&1 | awk '/user/ {print $2}'`

    # Extract the number of elements from the file name
    base_name="${input##*/}"
    size_number="${base_name%.*}"
    size=`echo $size_number | cut -d'_' -f 1`

    # Output the results to the file
    echo "$size   $cpu_time" >> $output_file
done