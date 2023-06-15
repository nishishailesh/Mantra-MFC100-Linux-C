#!/bin/sh
./my_scan_one_finger

for file in `find all_data`;
do
	if [ -f $file ];
	then
		echo $file is a file;
		./my_compare $file data.fmr
		if [ $? -eq 0 ] 
		then
		    echo $file is SUCCESS!!!!!!!!!!!!!!!!
		fi

	else
		echo $file is not a file;
	fi

done;

