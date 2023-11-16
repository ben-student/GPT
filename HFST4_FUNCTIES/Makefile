SOURCES=main.c \
		functies.c \
		
		
		


APP=main
# our compiler to compile the application
CXX=gcc
OBJS=$(patsubst %.c,%.o,$(SOURCES))
CXXFLAGS=-c -o0
 
# Default build sequence
all:$(APP)

# Link .o files to create the application
$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compile .c to .o files
.c.o:
	$(CXX) $(CXXFLAGS) $< -o $@
 
.PHONY: debug
 
# Debug mode: add -g flag and build executable
debug: CXXFLAGS += -g
debug: $(APP)

.PHONY: clean

clean:
	rm -f $(OBJS) $(APP)

