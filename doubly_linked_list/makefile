ODIR = bin

CC = gcc

CC_FLAGS = -std=c99 -Wall

LIBS = -lm

DEPS = doubly_linked_node.h doubly_linked_list.h

OBJ_ = main.o doubly_linked_node.o doubly_linked_list.o

OBJ  = $(patsubst %, $(ODIR)/%, $(OBJ_))

unit: $(OBJ)
	$(CC) $^ $(CC_FLAGS) -o $@ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $< -c $(CC_FLAGS) -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o unit
