CC := g++
CC_FLAGS := -Wall -s
LD_FLAGS := `allegro-config --libs` 
CCNAME := pong

MODULES   := . objects scenes utils
SRC_DIR   := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES))

SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ       := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES  := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(INCLUDES) $(CC_FLAGS) -c $$< -o $$@
endef

.PHONY: clean all checkdirs

all: clean checkdirs main.o $(CCNAME)

main.o: main.cpp
	$(CC) $(CC_FLAGS) -c main.cpp -o main.o $(LD_FLAGS)
	
$(CCNAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ main.o -o $@ $(LD_FLAGS)


checkdirs: $(BUILD_DIR)

$(BUILD_DIR):	
	@mkdir -p $@

clean:
	rm -f -r build/*
	rm -f $(CCNAME)
	rm -f main.o
	
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))


