#!/bin/bash

if [ $# -lt 2 ]; then
	echo "$0 <directory path> <string to write>"
	exit 1
fi

file_path=$1
write_string=$2

dir_path=$(dirname $file_path)
mkdir -p $dir_path

if [ $? -gt 0 ]; then
   echo "Error creating folder"
   exit 1
fi

echo $write_string > $file_path

if [ $? -gt 0 ]; then
   echo "Error creating file"
   exit 1
else
   echo "Success"
   exit 0
fi



