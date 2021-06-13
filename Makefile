DEFINES:=
a.out: main.cpp
	g++ main.cpp $(DEFINES)

.PHONY: test clean debug_setup recursive_setup

recursive_setup:
	$(eval DEFINES=-DRECURSIVE $(DEFINES))

recursive: recursive_setup a.out

debug_setup:
	$(eval DEFINES=-DDEBUG $(DEFINES))

debug: debug_setup a.out

test_debug: debug
	./a.out < input.txt

test: a.out
	./a.out < input.txt > output.txt && diff output.txt output1.txt

clean:
	rm -rf a.out
