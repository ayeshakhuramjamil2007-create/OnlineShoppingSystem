# Online Shopping and Order Management System

A menu-driven Online Shopping and Order Management System developed in C++ as a Data Structures and Algorithms Open Ended Lab project.

## Project Overview

This application manages product records, shopping cart operations, and customer orders. It uses linked lists and a queue to organize data and file handling to preserve product and pending-order information between program executions.

## Features

- Add, display, search, update, and delete products.
- Search products by ID, name, category, and price.
- Sort products by ID, name, category, and price.
- Add products to the shopping cart.
- Display and remove cart items.
- Calculate cart subtotals and grand total.
- Place customer orders.
- Process pending orders using FIFO (First In, First Out).
- Validate product availability and stock quantities.
- Save and load products and pending orders using files.

## Data Structures Used

- **Singly Linked List:** Used to store and manage product records.
- **Singly Linked List:** Used to manage shopping cart items.
- **Queue (Linked List Implementation):** Used to manage pending orders in FIFO order.

## Project Structure

| File | Description |
|---|---|
| `main.cpp` | Main menu and program execution |
| `product.cpp` | Product management, searching, sorting, and product file handling |
| `product.h` | Product structures and function declarations |
| `cart.cpp` | Shopping cart operations |
| `cart.h` | Cart structures and function declarations |
| `order.cpp` | Order placement, processing, and file handling |
| `order.h` | Order structures and function declarations |
| `products.txt` | Stores product records |
| `orders.txt` | Stores pending orders |
| `order_counter.txt` | Stores the next available order ID |
| `run.bat` | Automates compilation and execution |

## How to Run

### Requirements
- C++ compiler (g++)
- Windows operating system (for `run.bat`)

### Compile Manually

```bash
g++ main.cpp product.cpp cart.cpp order.cpp -o main
```

### Execute

```bash
.\main
```

Alternatively, run `run.bat` to compile and launch the application automatically.

## File Persistence

Product records, pending orders, and the next available order ID are saved in text files. The shopping cart is maintained in memory and is not saved between program runs.

## Project Information

- **Language:** C++
- **Course:** Data Structures and Algorithms
- **Project Type:** Open Ended Lab
