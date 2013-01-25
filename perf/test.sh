#!/bin/bash

# Test run time of each search method

methods=('hash' 'linear');
sizes=('1m' '3m' '5m');
test_runs=10

for method in "${methods[@]}"
do
	echo "$method:"

	for size in "${sizes[@]}"
	do
		total_time=0

		for (( i=0; i<=$test_runs; i++ ))
		do
			run_time=`./$method $size`
			total_time=$(( $run_time + $total_time ))
		done

		avg_time=$(( $total_time / $test_runs ))
		echo -e "\t$size: $avg_time usecs"
	done
done

