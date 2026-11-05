.DEFAULT_GOAL := run
.PHONY := run

run:
	@mkdir -p build
	@g++ main.cpp -o build/round-robin
	@build/round-robin
