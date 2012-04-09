
default:
	@echo If want to test with set_main and run the exicutable type in terminal \"make testrun\"
	@echo If just to get the executable \"make test\"
	@echo It to clean type in terminal \"make clean\"
test:
	gcc -Wall -fprofile-arcs -ftest-coverage -c set_main.c -lgcov
	gcc set_main.o ../src/job_queue.o -o test_set_main -lgcov

	#gcc -Wall -fprofile-arcs -ftest-coverage -c set_main.c -lgcov
	#gcc set_main.c ../src/job_queue.c -o test__set_main

testrun: test
	./test_set_main


clean: 
	rm -rf test_set_main *.o *.gc*