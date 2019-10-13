# the compiler: gcc for C program
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g

# the build target executable:
TARGET_1 = webserver
TARGET_2 = client

all: $(TARGET_1) $(TARGET_2)

$(TARGET_1): $(TARGET_1).c
	$(CC) $(CFLAGS) -o $(TARGET_1) $(TARGET_1).c

$(TARGET_2): $(TARGET_2).c
	$(CC) $(CFLAGS) -o $(TARGET_2) $(TARGET_2).c

clean:
	$(RM) $(TARGET_1) $(TARGET_2)
