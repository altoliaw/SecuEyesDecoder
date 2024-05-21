GIT_INSTALLED:=$(shell command -v git 2> /dev/null)
GIT_HASH="None"
Copy_RIGHT_DATE=$(shell date +"%Y")

ifndef GIT_INSTALLED
    # Obtaining git hash value
    GIT_HASH=$(shell git rev-parse --short HEAD)
endif

define HEREDOC
SECTIONS
{
	. = 0x100000;
	.license :
	{
		*(.license)
	}
}
endef

export HEREDOC

.Phony: all
all:	license.ld
	@$(shell echo "License information: ${GIT_HASH} | Copyright (c) $({Copy_RIGHT_DATE}) CobraSonic Software" \
	> license.txt)
	ld -r -b binary -o license.o license.txt


.Phony: clean
clean:
	@rm license.*

license.ld:
	@echo "$$HEREDOC" > license.ld

