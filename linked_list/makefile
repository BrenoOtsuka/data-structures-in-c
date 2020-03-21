ODIR = bin

CC = gcc

CC_FLAGS = -std=c99 -Wall

LIBS = -lm

DEPS = linked_node.h linked_list.h

OBJ_ = main.o linked_node.o linked_list.o

OBJ  = $(patsubst %, $(ODIR)/%, $(OBJ_))

unit: $(OBJ)
	$(CC) $^ $(CC_FLAGS) -o $@ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $< -c $(CC_FLAGS) -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o unit
