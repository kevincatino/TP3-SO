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


all: $(SERVER) $(CLIENT)


$(SERVER): $(OBJECTS_SERVER) $(OBJECTS_CHALLENGES)
	@$(GCC) $(GCCFLAGS) $(OBJECTS_SERVER) $(OBJECTS_CHALLENGES) -o $(TARGET_SERVER) $(GCCLM)
	-@rm -rf $(OBJECTS_SERVER)
	-@rm -rf $(OBJECTS_CHALLENGES)
	@echo "\033[3;36m[Server compiled]\033[0m"


$(CLIENT): $(OBJECTS_CLIENT)
	@$(GCC) $(GCCFLAGS) $< -o $(TARGET_CLIENT)
	-@rm -rf $(OBJECTS_CLIENT)
	@echo "\033[3;36m[Client compiled]\033[0m"


%.o: %.c
	@$(GCC) $(GCCFLAGS) -I./include -c $< -o $@ $(GCCLM)
	@echo "\033[32mCompiled object file \033[0m $@"


clean:
	-@rm -rf $(TARGETS)
	-@rm -rf $(OBJECTS_SERVER)
	-@rm -rf $(OBJECTS_CHALLENGES)
	@echo "\033[3;35m[src cleaned]\033[0m"
