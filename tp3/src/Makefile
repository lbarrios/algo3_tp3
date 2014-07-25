UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MAKE := make
endif
ifeq ($(UNAME_S),FreeBSD)
	MAKE := gmake
endif

.PHONY: clean greedy all backtracking grasp local_search greedy_heuristic_All greedy_a greedy_b greedy_c

all: greedy backtracking grasp local_search

greedy: greedy_a greedy_b greedy_c greedy_all

greedy_a:
	cd greedy_heuristic_A && $(MAKE) && $(MAKE) time
greedy_b:
	cd greedy_heuristic_B && $(MAKE) && $(MAKE) time
greedy_c:
	cd greedy_heuristic_C && $(MAKE) && $(MAKE) time

greedy_all:
	cd greedy_heuristic_All && $(MAKE) && $(MAKE) time

backtracking:
	cd backtracking && $(MAKE) && $(MAKE) time

grasp:
	cd grasp && $(MAKE) && $(MAKE) time

local_search:
	cd local_search && $(MAKE) && $(MAKE) time

clean:
	cd backtracking && $(MAKE) clean
	cd grasp && $(MAKE) clean
	cd greedy_heuristic_A && $(MAKE) clean
	cd greedy_heuristic_B && $(MAKE) clean
	cd greedy_heuristic_C && $(MAKE) clean
	cd greedy_heuristic_All && $(MAKE) clean
	cd local_search && $(MAKE) clean
