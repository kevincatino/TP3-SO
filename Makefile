all: src
	@echo "\033[1;3;36m[Proyect compiled]\033[0m"

src: 
	@cd src; make all
	@echo "\033[1;1;34m[src compiled]\033[0m"

clean:
	@cd src; make clean
	@echo "\033[1;3;35m[Proyect cleaned]\033[0m"

recompile:
	@make clean; make all
	@echo "\033[1;3;37m[Proyect recompile]\033[0m"

.PHONY: src all clean recompile