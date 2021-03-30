ZEUS = $(shell seq 1 12)
TIMES = $(shell seq 1 30) 

build:
	mpicc -o mpi_pi.x mpi_pi.c

strong:
	@echo Skalowanie silne [n = $(n)]:
	@for time in $(TIMES); do \
		for p in $(ZEUS); do \
			mpiexec -np $$p ./mpi_pi.x $(n) 2>/dev/null ; \
		done ; \
		printf "\n" ; \
	done
	@printf "\n"

weak:
	@echo Skalowanie slabe [n = $(n)]:
	@for time in $(TIMES); do \
		for p in $(ZEUS); do \
			mpiexec -np $$p ./mpi_pi.x $$(( $$p * $(n) )) 2>/dev/null ; \
		done ; \
		printf "\n" ; \
	done
	@printf "\n"

clean:
	rm -rf *.x
