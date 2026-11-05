.DEFAULT_GOAL := run
.PHONY := run

run:
	@mkdir -p build
	@g++ main.cpp -o build/round-robin

	@build/round-robin < 1.in > 1.out
	@diff 1.out 1.oracle && echo "Test 1 passed"

	@build/round-robin < 2.in > 2.out
	@diff 2.out 2.oracle && echo "Test 2 passed"
