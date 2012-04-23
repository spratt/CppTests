TESTS = test test2 test3 test4

all: ${TESTS}

run: all
	${foreach test,${TESTS}, ./${test};}