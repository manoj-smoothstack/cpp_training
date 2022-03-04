MYDIR = .
all:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make all && cd -; done

test:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make test && cd -; done

clean:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make clean && cd -; done

cleandep:
	@for f in $(shell ls ${MYDIR} | grep -v Makefile); do cd $${f} && make cleandep && cd -; done
