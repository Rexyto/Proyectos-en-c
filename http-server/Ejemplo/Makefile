CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lws2_32 -luser32
TARGET = servidor.exe
SOURCE = server.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	del /f $(TARGET)

setup:
	if not exist src mkdir src

.PHONY: all run clean setup