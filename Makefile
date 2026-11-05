.DEFAULT_GOAL := run
.PHONY := run

run:
	@g++ main.cpp -o round-robin
	@./round-robin
