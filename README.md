# resistor-value-finder

When designing circuits, I often need two resistors to have a certain ratio, but resistors only come in discrete values. This program finds a pair of standard values that closely approximate the target ratio. 

## How it works

The 3 most common series of [standard resistors](https://eepower.com/resistor-guide/resistor-standards-and-codes/resistor-values/#) are E12, E24, and E48.

```
E12: 
    1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2 
E24: 
    1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 
    3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1
E48:
    1.00, 1.05, 1.10, 1.15, 1.21, 1.27,
    1.33, 1.40, 1.47, 1.54, 1.62, 1.69,
    1.78, 1.87, 1.96, 2.05, 2.15, 2.26,
    2.37, 2.49, 2.61, 2.74, 2.87, 3.01,
    3.16, 3.32, 3.48, 3.65, 3.83, 4.02,
    4.22, 4.42, 4.64, 4.87, 5.11, 5.36,
    5.62, 5.90, 6.19, 6.49, 6.81, 7.15,
    7.50, 7.87, 8.25, 8.66, 9.09, 9.53
```

This program will find 3 possible combinations of resistors: a pair where both R1 and R2 are taken from E12, a pair where they may be from E12 or E24, and a pair where they may be from any series. This is because E48 is not as common as E12 or E24.

It runs in `O(n^2)` time where n is the number of values in the series (not very efficient, but the data sets are so tiny so who cares).

## Useage

### Building

to build do: `make`

to clean do: `make clean`

### Running

to run do: 

1. `make run`
2. input any positive number

possible output.

```
./resistor_value_finder.out
Resistor Value Calculator
Please input the target ratio R1/R2:
4.11
[E12] 33/8.2 (4.02439)
[E24] 16/3.9 (4.10256)
[E48] 15/3.65 (4.10959)
```

each series gives a better and better approximation of the target ratio 4.11. The most accurate resistor combination would be a 15k and 3.65k resistor.