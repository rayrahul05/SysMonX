CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
APP := bin/sysmonx
SRC := src/main.cpp src/SystemMonitor.cpp src/DeviceInterface.cpp
OBJ := $(SRC:src/%.cpp=build/%.o)

.PHONY: all app clean driver

all: app

app: $(APP)

$(APP): $(OBJ)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

driver:
	$(MAKE) -C driver

clean:
	rm -rf build bin
	-$(MAKE) -C driver clean
