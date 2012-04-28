default:
	@echo "--- Normal compilation ----------------------------------"
	@echo "make pclog     produces binary in src/"
	@echo " "
	@echo "--- Cleaning up -----------------------------------------"
	@echo "make clean    recursively clean up subdirs"
	@echo " "
	@echo "--- Verification and debugging --------------------------"
	@echo "make check        run unit tests"
	@echo "make gcovunit     run unit tests with gcov (statement coverage)"
	@echo "make gcovunitb    run unit tests with gcov (branch coverage)"
	@echo "make memunit      run unit tests with valgrind"

pclog:
	cd src && $(MAKE) pclog

clean:
	cd src && $(MAKE) clean
	cd test && $(MAKE) clean


check:  
	cd src && $(MAKE) testobjs
	cd test && $(MAKE) check 


gcovcheck: clean
	cd src && $(MAKE) testobjscov
	cd test && $(MAKE) gcovcheck


gcovunitb: clean
	cd src && $(MAKE) testobjscov
	cd test && $(MAKE) gcovcheck

memunit: clean
	cd src && $(MAKE) testobjsgdb
	cd test && $(MAKE) memcheck

