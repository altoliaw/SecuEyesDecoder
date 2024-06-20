GIT_INSTALLED:=$(shell command -v git 2> /dev/null)
GIT_HASH="None"
Copy_RIGHT_DATE=$(shell date +"%Y")

ifdef GIT_INSTALLED
    # Obtaining git hash value
    GIT_HASH=$(shell git rev-parse --short HEAD)
endif

# define HEREDOC
# SECTIONS
# {
#     .version :
#     {
#         KEEP(*(.version))
#     }
# }
# endef

# export HEREDOC

.Phony: all
all:
	@$(shell echo "Version information: ${GIT_HASH} | Copyright (c) $({Copy_RIGHT_DATE}) CobraSonic/Dataisec Software" \
	> git_version.txt)
	ld -r -b binary -o git_version.o git_version.txt


.Phony: clean
clean:
	@rm -rf git_version.*

# version.ld:
# 	@echo "$$HEREDOC" > version.ld