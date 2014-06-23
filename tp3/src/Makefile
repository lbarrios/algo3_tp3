UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MAKE := make
endif
ifeq ($(UNAME_S),FreeBSD)
	MAKE := gmake
endif

.PHONY: clean
clean:
	cd backtracking && $(MAKE) clean
	cd grasp && $(MAKE) clean
	cd greedy_heuristic_A && $(MAKE) clean
	cd greedy_heuristic_B && $(MAKE) clean
	cd greedy_heuristic_C && $(MAKE) clean
	cd local_search && $(MAKE) clean
