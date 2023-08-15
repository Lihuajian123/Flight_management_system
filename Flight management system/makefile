TARCET=main
SRCT=$(wildcard *.c)
CC=gcc
OBJS=$(patsubst %.c, %.o, $(SRCT)) 
#目标：依赖
#版本五
$(TARCET):$(OBJS)
	$(CC) -o  $(TARCET) $(OBJS)
%.o:%.c
	$(CC) -o $@ -c $<
#版本六 （$@表示目标， $<初级依赖， $^终级依赖）
#$(TARGET):$(OBJS)   
#	$(CC) -o $@  $^
#自动清除功能
clean:
	rm *.o $(TARGET)
