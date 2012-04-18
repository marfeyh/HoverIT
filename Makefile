all: 
	cd src && $(MAKE) 

check: 
	cd src && $(MAKE) check

clean:
	cd src && $(MAKE) clean 

.PHONY: all check clean
