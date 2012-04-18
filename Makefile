all:
	$(MAKE) all -C src/embedded
	$(MAKE) all -C src/computer

embedded:
	$(MAKE) all -C src/embedded

clean:
	$(MAKE) clean -C src/embedded
	$(MAKE) clean -C bin