GIT_INSTALLED:=$(shell command -v git 2> /dev/null)
GIT_HASH="None"
Copy_RIGHT_DATE=$(shell date +"%Y")

ifndef GIT_INSTALLED
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
	> version.txt)
	ld -r -b binary -o version.o version.txt


.Phony: clean
clean:
	@rm -rf version.*

# version.ld:
# 	@echo "$$HEREDOC" > version.ld