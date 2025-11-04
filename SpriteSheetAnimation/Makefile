CC=gcc

CACHE = .cache
RELEASE = $(CACHE)/release
TARGET = spritesheet


PKGS += raylib

CFLAGS += -Wall -Wextra -pedantic
CFLAGS += $$(pkg-config --cflags $(PKGS))

LIBS += $$(pkg-config --libs $(PKGS))

OBJS += $(CACHE)/main.o


all: build


$(CACHE)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@


build: env $(RELEASE)/$(TARGET)


$(RELEASE)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@


exec: build
	$(RELEASE)/$(TARGET)


env:
	mkdir -pv $(CACHE)
	mkdir -pv $(RELEASE)

clean:
	rm -rvf $(CACHE)

