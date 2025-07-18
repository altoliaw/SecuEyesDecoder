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
	@rm -rf ${Prdir}/*.exe
	@rm -rf ${Prdir}/*.o
	@rm -rf ${Prdir}/*/*.o
	@rm -rf ${Prdir}/Outputs/DLL/*.dll
	@rm -rf ${Prdir}/Outputs/DOT_A/*.a
	@make -f gitVersionByMk.mk clean

.Phony: cmakeClean
cmakeClean:
	@clear
	@rm -rf ${Prdir}/build/*
	@rm -rf ${Prdir}/build/*/*
	@rm -rf ${Prdir}/Outputs/*.txt

.Phony: run
run:
	@${Prdir}/${PjN}

# Creating the DLL for the window platform
.Phony: archiveDLL
archiveDLL: ${Prdir}/${PjN}
	@make compiliedVersion
	@mkdir -p Outputs && cd Outputs && mkdir -p DLL && cd ../../
	
	@gcc -shared -o ./Outputs/DLL/jsonDecoder.dll \
	${Sources}/BuildDLL/BuildDLL.o \
	${Sources}/ParseSqlStmt.o \
	git_version.o \
	-L./

	@mkdir -p Outputs && cd Outputs && mkdir -p DOT_A && cd ../../

	@ar rcs ./Outputs/DOT_A/libjsonDecoder.a \
	${Sources}/BuildDLL/BuildDLL.o \
	${Sources}/ParseSqlStmt.o \
	git_version.o 



# Creating the DLL with a specified version
.Phony: compiliedVersion
compiliedVersion: PreRquest	${Prdir}/${PjN}compiliedVersion

# Creating the DLL for the window platform for test
PreRquest:
	@make -f gitVersionByMk.mk

##================================================================
# Creating a output objects for DLL
${Prdir}/${PjN}BuildDLL: 	${Sources}/BuildDLL/BuildDLL.o \
							${Sources}/ParseSqlStmt.o


# Creating a output objects for DLL to verify the version
${Prdir}/${PjN}compiliedVersion: 	${Prdir}/Mains/MainDLL.o \
									${Sources}/BuildDLL/BuildDLL.o \
									${Sources}/ParseSqlStmt.o
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Fsg} -o ${Prdir}/${PjN}_compiliedVersion \
		${Prdir}/Mains/MainDLL.o \
		${Sources}/BuildDLL/BuildDLL.o \
		${Sources}/ParseSqlStmt.o \
		${Prdir}/git_version.o
		

# Main for BuildDLL
${Prdir}/Mains/MainDLL.o:
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Prdir}/Mains/MainDLL.c -c ${Fsg} -o ${Prdir}/Mains/MainDLL.o

# BuildDLL
${Sources}/BuildDLL/BuildDLL.o:	${Headers}/BuildDLL/BuildDLL.h ${Headers}/ParseSqlStmt.h ${Sources}/BuildDLL/BuildDLL.c
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Sources}/BuildDLL/BuildDLL.c -c ${Fsg} -o ${Sources}/BuildDLL/BuildDLL.o

##================================================================
# Creating a output objects for the C framework
${Prdir}/${PjN}: 	${Prdir}/Mains/Main.o \
					${Sources}/ParseSqlStmt.o
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Fsg} -o ${Prdir}/${PjN} \
		${Prdir}/Mains/Main.o \
		${Sources}/ParseSqlStmt.o

# Main
${Prdir}/Mains/Main.o:	${Headers}/ParseSqlStmt.h ${Prdir}/Mains/Main.c
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Prdir}/Mains/Main.c -c ${Fsg} -o ${Prdir}/Mains/Main.o

# ParseSqlStmt
${Sources}/ParseSqlStmt.o:	${Headers}/ParseSqlStmt.h ${Headers}/ArrayOfPointerOfString.h ${Sources}/ParseSqlStmt.c
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} ${Sources}/ParseSqlStmt.c -c ${Fsg} -o ${Sources}/ParseSqlStmt.o

	
# ArrayOfPointerOfString
${Sources}/ArrayOfPointerOfString.o: ${Sources}/ArrayOfPointerOfString.c ${Headers}/ArrayOfPointerOfString.h
	${Cmp} ${Stdlib} ${Cmpopt} ${Detinfo} ${Wall} $< -c ${Fsg} -o $@