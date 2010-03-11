tests: list_tests run_tests
clean: tests_clean
tests_clean:
	rm -f testlist *.out tests-summary.log_out
list_tests:
	./list-tests > testlist
run_tests:
	./run-tests -v 2>&1 | tee tests-summary.log_out
