ONLINE SHOPPING AND ORDER MANAGEMENT SYSTEM

Modules:
- main.cpp: Main menu and program execution.
- product.cpp / product.h: Product linked list, CRUD, searching, sorting, products.txt.
- cart.cpp / cart.h: Shopping cart linked list and cart operations.
- order.cpp / order.h: FIFO order queue and order file handling.

Compile:
g++ -std=c++11 main.cpp product.cpp cart.cpp order.cpp -o shopping

Run in Windows PowerShell:
.\shopping.exe

Keep products.txt, orders.txt, and order_counter.txt in the program's working directory.
They are created/updated by the application.
