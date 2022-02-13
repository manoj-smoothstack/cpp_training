#MYDIR = .
all:
	@for f in $(shell ls -d Day*/examples | grep -v Makefile | grep -v Day30); do cd $${f} && make all && cd -; done

test:
	@for f in $(shell ls -d Day*/examples | grep -v Makefile | grep -v Day30); do cd $${f} && make test && cd -; done

clean:
	@for f in $(shell ls -d Day*/examples | grep -v Makefile | grep -v Day30); do cd $${f} && make clean && cd -; done

cleandep:
	@for f in $(shell ls -d Day*/examples | grep -v Makefile | grep -v Day30); do cd $${f} && make cleandep && cd -; done
