
CXX := g++
COMMON_CXX_FLAGS := -std=c++20 -O3 -Wall -Werror

SRC_DIR := src
BUILD_DIR := build

all: dlang 

########################
# DLANG INFRASTRUCTURE #
########################

CXX_FLAGS := $(COMMON_CXX_FLAGS) -I infra/dlex

DLEX_CPP := $(wildcard infra/dlex/*.cpp)

$(BUILD_DIR)/dlex: $(DLEX_CPP)
	$(CXX) $(CXX_FLAGS) $^ -o $@

src/lexer/generated_lexer.hpp: $(BUILD_DIR)/dlex src/lexer/spec.dlex
	$(BUILD_DIR)/dlex src/lexer/spec.dlex > $@

##################
# DLANG COMPILER #
##################

CXX_FLAGS := $(COMMON_CXX_FLAGS) -I src

DLANG_CPP := $(SRC_DIR)/dlang.cpp

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

LEXER_CPP = $(wildcard $(SRC_DIR)/lexer/*.cpp)

$(BUILD_DIR)/lexer.o: $(LEXER_CPP) src/lexer/generated_lexer.hpp
	$(CXX) $(CXX_FLAGS) -c $(LEXER_CPP) -o $@

dcc: $(DLANG_CPP) $(BUILD_DIR)/lexer.o
	$(CXX) $(CXX_FLAGS) $^ -o $@

.PHONY: dlang
dlang: $(BUILD_DIR) dcc

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm src/lexer/generated_lexer.hpp
	rm dcc

