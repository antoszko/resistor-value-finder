OUT = resistor_value_finder.out
SRC = main.cpp
CXX_FLAGS = -std=c++11 -O3


$(OUT):  $(SRC)
	g++ $(SRC) -o $(OUT) $(CXX_FLAGS)


.PHONY: run clean

run: $(OUT)
	./$(OUT)

clean:
	rm $(OUT)