ODIR = bin

CC = gcc

CC_FLAGS = -std=c99 -Wall

LIBS = -lm

DEPS = binary_search_node.h binary_search_tree.h

OBJ_ = main.o binary_search_node.o binary_search_tree.o

OBJ  = $(patsubst %, $(ODIR)/%, $(OBJ_))

unit: $(OBJ)
	$(CC) $^ $(CC_FLAGS) -o $@ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $< -c $(CC_FLAGS) -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o unit
