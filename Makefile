# Usage:
# make			# compile all binary

.PHONY = all

CC = g++

SRCS := main.cpp execute_command.cpp
OUT := dwmcppbar

all: build

build:
	@echo "Building dwmcppbar..."
	${CC} -o ${OUT} ${SRCS}

clean:
	@echo "Cleaning..."
	rm ./${OUT}