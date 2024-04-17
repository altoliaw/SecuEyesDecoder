#!/bin/sh
# Environmental variable(s)
currentWorkingDir=$(pwd)
projectName=Test

# Executing the command from the make file
make cmakeClean

# Creating the directory
mkdir -m 777 build 2>/dev/null
cd build

cmake ../ && make

# If the command, cmake ../ && make, works, ...
if [ $? -eq 0 ]; then
	# Entering the unit test folder
	cd Tests
	./$projectName.exe
fi 
cd $currentWorkingDir