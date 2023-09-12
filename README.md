# 🧮 Push_swap 🧮

## 👋 A brief intro

Push Swap is a project to code a program that sorts a stack of integers using only specific operations and two stacks.

## 🌚 What does it do?

The program takes a random list of integers as input and prints out a series of instructions to sort the numbers in ascending order using two stacks (stack A and stack B) and limited operations.

## 🏃 Usage

To run the program:

Compile with make

Run ./push_swap [input] example (./push_swap "1 0 12 -12 77 8" or ./push_swap 1 0 12 -12 77 8).

## 🎓 Skills developed

- Implementing stacks with linked lists
- Assigning indexes and calculating positions of elements
- Choosing the optimal next operation based on move costs
- Sorting algorithms for small (3 elements) and large lists

## 👨‍🏫 Test with checker

ARG="728 380 800 181 683 329 760 532 638 306 900 884 970 203 326 468 267 523 78 759 273 864 401 120 221 445 506 868 12 553"; ./push_swap $ARG | ./checker_Mac $ARG

The checker validates if the numbers are correctly sorted:
To compile:

## 🧑 Visualize with pyviz

For visualizations, run:

python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`

## 📚 Resources

This project was inspired by an article that explains an efficient algorithm approach:
https://web.archive.org/web/20220802162832/https://www.codequoi.com/en/push_swap-efficient-positional-sorting-algorithm/

