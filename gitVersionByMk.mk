GIT_INSTALLED:=$(shell command -v git 2> /dev/null)
GIT_HASH="None"
COPY_RIGHT_DATE=$(shell date +"%Y")

ifdef GIT_INSTALLED
    # Obtaining git hash value
    GIT_HASH=$(shell git rev-parse --short HEAD)
endif

.Phony: all
all:
	@$(shell echo "Version information: ${GIT_HASH} | Copyright (c) $({COPY_RIGHT_DATE}) CobraSonic/Dataisec Software" \
	> git_version.txt)
	ld -r -b binary -o git_version.o git_version.txt


.Phony: clean
clean:
	@rm -rf git_version.*
