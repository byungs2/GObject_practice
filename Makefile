#CC=/usr/local/bin/gcc-11
CC=gcc
CFLAGS=`pkg-config --cflags glib-2.0 gio-2.0 gobject-2.0`
LIBS=`pkg-config --libs glib-2.0 gio-2.0 gobject-2.0`

TARGET=main

SRC=main.c test_animal.c cat.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)

