# Project root path from (to project)
Prdir:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
Headers=${Prdir}/Headers
Sources=${Prdir}/Sources

# Setting of the general compiled grammer
## The Compiler, library, level of the compiler optimization, detected information, wall and message
Cmp=gcc
Stdlib=-std=c99
Cmpopt=-O3
Detinfo=-g3
Wall=-Wall
Fsg=-fmessage-length=0 -pthread
#OpenSSL3=-I../../../include
OpenSSL3=

## Project execution's name
PjN:= $(word $(words $(subst /, ,${Prdir})), $(subst /, ,${Prdir}))

# Make's Processes
.Suffixs: .c .h

.Phony: all
all: ${Prdir}/${PjN}
	@make run

.Phony: clean
clean:
	@clear
	@rm -rf ${Sources}/*.o
	@rm -rf ${Sources}/*/*.o
	@rm -rf ${Prdir}/${PjN}
	@rm -rf ${Prdir}/*.o

.Phony: cmakeClean
cmakeClean:
	@clear
	@rm -rf ${Prdir}/build/*
	@rm -rf ${Prdir}/build/*/*

.Phony: run
run:
	@${Prdir}/${PjN}

##================================================================
# Create a module
${Prdir}/${PjN}: 	${Prdir}/Main.o \
					${Sources}/ParseSqlStmt.o

	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Fsg} -o ${Prdir}/${PjN} \
		${Prdir}/Main.o \
		${Sources}/ParseSqlStmt.o

# Main
${Prdir}/Main.o:	${Headers}/ParseSqlStmt.h ${Prdir}/Main.c
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Prdir}/Main.c -c ${Fsg} -o ${Prdir}/Main.o

# ParseSqlStmt
${Sources}/ParseSqlStmt.o:	${Headers}/ParseSqlStmt.h ${Sources}/ParseSqlStmt.c
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Sources}/ParseSqlStmt.c -c ${Fsg} -o ${Sources}/ParseSqlStmt.o