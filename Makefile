default:
	@echo "--- Normal compilation ----------------------------------"
	@echo "make all     produces binary in bin/"
	@echo " "
	@echo "--- Cleaning up -----------------------------------------"
	@echo "make clean    recursively clean up subdirs"
	@echo " "
	@echo "--- Verification and debugging --------------------------"
	@echo "make unit      run unit tests"

all:
	cd src && $(MAKE) all

clean:
	cd src && $(MAKE) clean
	cd tests/unit && $(MAKE) clean

unit:
	cd src && $(MAKE) testobjs
	cd tests/unit && $(MAKE) unit
