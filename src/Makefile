include Makefile.inc

SOURCES_SERVER := server.c 
SOURCES_CLIENTE := client.c
SOURCES_CHALLENGES := challenges.c

OBJECTS_SERVER := server.o 
OBJECTS_CLIENT := client.o
OBJECTS_CHALLENGES := challenges.o

TARGET_SERVER := ../server
TARGET_CLIENT := ../client
TARGETS := $(TARGET_SERVER) $(TARGET_CLIENT)



all: server client


server: $(OBJECTS_SERVER) $(OBJECTS_CHALLENGES)
	@$(GCC) $(GCCFLAGS) $(OBJECTS_SERVER) $(OBJECTS_CHALLENGES) -o $(TARGET_SERVER) $(GCCLM)
	-@rm -rf $(OBJECTS_SERVER)
	-@rm -rf $(OBJECTS_CHALLENGES)
	@echo -e "\e[3;36m[Server compiled] \e[0m"


client: $(OBJECTS_CLIENT)
	@$(GCC) $(GCCFLAGS) $< -o $(TARGET_CLIENT)
	-@rm -rf $(OBJECTS_CLIENT)
	@echo -e "\e[3;36m[Client compiled] \e[0m"


%.o: %.c
	@$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLM)
	@echo -e "\e[32mCompiled object file\e[0m $@"


clean:
	-@rm -rf $(TARGETS)
	-@rm -rf $(OBJECTS_SERVER)
	-@rm -rf $(OBJECTS_CHALLENGES)
	@echo -e "\e[3;35m[src cleaned] \e[0m"
