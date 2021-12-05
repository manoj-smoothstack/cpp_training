MYDIR = .
all:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make all; done

test:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make test; done

clean:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make clean; done

cleandep:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make cleandep; done
