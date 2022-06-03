all:
	@cd src; make all
	@echo "\033[1;3;36m[Proyect compiled]\033[0m"

clean:
	@cd src; make clean
	@echo "\033[1;3;35m[Proyect cleaned]\033[0m"

recompile:
	@make clean; make all

.PHONY: all clean recompile