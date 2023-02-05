# Makefile

IDIR =../include
CC=gcc
CFLAGS= -g -O0 -I$(IDIR) -std=c99
LDFLAGS=
ODIR=obj
LDIR =../lib
LIBS=-lm

all: big_build

# Makefile config
BUILD_DIR=build
SOURCE_PATH=src
DEPS = $(shell find $(SOURCE_PATH) -name '*.h')
SRCS = $(shell find $(SOURCE_PATH) -name '*.c')       # src/client.c src/main.c src/menu.c
OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(SRCS:.c=.o)))

$(BUILD_DIR)/rewards.o: $(SOURCE_PATH)/rewards.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/main.o: $(SOURCE_PATH)/main.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/menu.o: $(SOURCE_PATH)/menu.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR)/logger.o: $(SOURCE_PATH)/logger.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR):
	mkdir $@

%.o: %c $(DEPS)
	$(CC) -c -o $(BUILD_DIR)/$@ $< $(CFLAGS)

main: $(OBJS)
	@echo "[LINK] $^"
	$(CC) -o $(BUILD_DIR)/CochlearRewards $^ $(CFLAGS) $(LIBS) 

big_build: $(main) 
	@echo "[CC] $<"
	@echo  .....main app compiled.

.PHONY: clean

clean:
	$(RM) $(BUILD_DIR) 

list_src:
	@echo $(shell find src -name '*.c')

#  macros $@ and $^, which are the left and right sides of the :
#  the $< is the first item in the dependencies list