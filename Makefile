CC=gcc  #compiler
TARGET=main #target file name
 
all:
	flex Lexico.l
	$(CC) *.c -o $(TARGET)
	./$(TARGET)
clean:
	rm $(TARGET)
