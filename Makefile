.PHONY: build

build:
	g++ -fdiagnostics-color=always -g $(SOURCE) -o /tmp/problem -DLOCALENV
