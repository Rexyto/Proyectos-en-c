<<<<<<< HEAD
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

=======
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

>>>>>>> 14c637ae789a6a4ac50b2a6dbb9263ceb88de4c8
.PHONY: all run clean setup