OUT = resistor_value_finder
SRC = main.cpp
CXX_FLAGS = -std=c++11 -O3
INSTALL_PATH = $(HOME)/.local/bin
INSTALL_FILE = $(INSTALL_PATH)/$(OUT)

$(OUT):  $(SRC)
	g++ $(SRC) -o $(OUT) $(CXX_FLAGS)

.PHONY: run clean install uninstall

run: $(OUT)
	./$(OUT)

clean:
	rm $(OUT)

install: $(INSTALL_FILE)

$(INSTALL_FILE): $(OUT)
	cp $(OUT) $(INSTALL_PATH)

uninstall:
ifneq (,$(wildcard $(INSTALL_FILE)))
	rm $(INSTALL_FILE)
else
	@echo File not installed!
endif	
	