ODIR = bin

CC = gcc

CC_FLAGS = -std=c99 -Wall

LIBS = -lm

DEPS = linked_list.h

OBJ_ = unit_tester.o linked_list.o

OBJ  = $(patsubst %, $(ODIR)/%, $(OBJ_))

unit_tester: $(OBJ)
	$(CC) $^ $(CC_FLAGS) -o $@ $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $< -c $(CC_FLAGS) -o $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o unit_tester
