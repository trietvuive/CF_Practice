CC = g++
CFLAGS = -g -wall
TARGET = 118E
all: $(TARGET)

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
clean:
			$(RM) $(TARGET)