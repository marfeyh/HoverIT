all:
	$(MAKE) all -C src/embedded
	$(MAKE) all -C src/computer

embedded:
	$(MAKE) all -C src/embedded

embedded-check:
	$(MAKE) check -C src/embedded

embedded-gcov:
	$(MAKE) gcovcheck -C src/embedded

clean:
	$(MAKE) clean -C src/embedded
	$(MAKE) clean-tests -C src/embedded
	$(MAKE) clean -C bin