#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

struct Node
{
    Product data;
    Node* next;
};

Node* head = NULL;

struct CartNode {
    int id;
    string name;
    double price;
    int quantity;
    CartNode* next;
};

CartNode* cartHead = NULL;

struct Order {
    int orderID;
    double total;
    CartNode* items;
    Order* next;
};

Order* front = NULL;
Order* rear = NULL;

int nextOrderID = 1;


// Function to search for a product by ID
Node* searchProduct(int searchID) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data.id == searchID) {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

// Function to display the search product menu
void searchProductMenu() {
    int id;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    Node* result = searchProduct(id);

    if (result == NULL) {
        cout << "\nProduct not found!\n";
    } else {
        cout << "\nProduct Found!\n";
        cout << "Name: " << result->data.name << endl;
        cout << "Category: " << result->data.category << endl;
        cout << "Price: " << result->data.price << endl;
        cout << "Quantity: " << result->data.quantity << endl;
    }
}

// Search product by name
void searchProductByName() {
    string searchName;
    bool found = false;

    cout << "\nEnter Product Name to search: ";
    cin >> searchName;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.name == searchName) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nProduct not found!\n";
    }
}

// Search product by category
void searchProductByCategory() {

    string searchCategory;
    bool found = false;

    cout << "\nEnter Category to search: ";
    cin >> searchCategory;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.category == searchCategory) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo product found in this category!\n";
    }
}


// Search product by price
void searchProductByPrice() {

    double searchPrice;
    bool found = false;

    cout << "\nEnter Product Price to search: ";
    cin >> searchPrice;

    Node* temp = head;

    while (temp != NULL) {

        if (temp->data.price == searchPrice) {

            cout << "\nProduct Found!\n";
            cout << "ID: " << temp->data.id << endl;
            cout << "Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Quantity: " << temp->data.quantity << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        cout << "\nNo product found at this price!\n";
    }
}


// Save products into a file
void saveProducts() {

    ofstream file("products.txt");

    Node* temp = head;

    while (temp != NULL) {

        file << temp->data.id << " "
             << temp->data.name << " "
             << temp->data.category << " "
             << temp->data.price << " "
             << temp->data.quantity << endl;

        temp = temp->next;
    }

    file.close();

    cout << "\nProducts saved successfully!\n";
}

// Load products from a file
void loadProducts() {

    ifstream file("products.txt");

    if (!file) {
        return;
    }

    while (true) {

        Node* newNode = new Node;

        if (!(file >> newNode->data.id
                   >> newNode->data.name
                   >> newNode->data.category
                   >> newNode->data.price
                   >> newNode->data.quantity)) {

            delete newNode;
            break;
        }

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    file.close();

    cout << "\nProducts loaded successfully!\n";
}


// Insert product at the end
void addProduct()
{
    Node* newNode = new Node;

    cout << "\nEnter Product ID: ";
    cin >> newNode->data.id;

    if (searchProduct(newNode->data.id) != NULL) {
        cout << "\nError! Product ID already exists.\n";
        delete newNode;
        return;
    }

    cout << "Enter Product Name: ";
    cin >> newNode->data.name;

    cout << "Enter Price: ";
    cin >> newNode->data.price;

    
        if (newNode->data.price <= 0) {
        cout << "\nInvalid price!"
             << "\nPrice must be greater than 0.\n";
        delete newNode;
        return;
    }

    cout << "Enter Quantity: ";
    cin >> newNode->data.quantity;
    
    if (newNode->data.quantity <= 0) {
        cout << "\nInvalid quantity!"
             << "\nQuantity must be greater than 0.\n";
        delete newNode;
        return;
    }

    cout << "Enter Category: ";
    cin >> newNode->data.category;

    cout << "Enter Price: ";
    cin >> newNode->data.price;

    cout << "Enter Quantity: ";
    cin >> newNode->data.quantity;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nProduct added successfully!\n";

    saveProducts();
}

// Display all products
void displayProducts()
{
    if (head == NULL)
    {
        cout << "\nNo products available!\n";
        return;
    }

    Node* temp = head;

    cout << "\n----- PRODUCT LIST -----\n";

    while (temp != NULL)
    {
        cout << "\nID: " << temp->data.id;
        cout << "\nName: " << temp->data.name;
        cout << "\nCategory: " << temp->data.category;
        cout << "\nPrice: " << temp->data.price;
        cout << "\nQuantity: " << temp->data.quantity;
        cout << "\n------------------------\n";

        temp = temp->next;
    }
}

// Update product
void updateProduct() {
    int id;

    cout << "\nEnter Product ID to update: ";
    cin >> id;

    Node* result = searchProduct(id);

    if (result == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "\nEnter New Name: ";
    cin >> result->data.name;

    cout << "Enter New Category: ";
    cin >> result->data.category;

    cout << "Enter New Price: ";
    cin >> result->data.price;

    cout << "Enter New Quantity: ";
    cin >> result->data.quantity;

    cout << "\nProduct updated successfully!\n";

    saveProducts();
}

// Delete product
void deleteProduct() {
    int id;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->data.id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    if (previous == NULL) {
        head = temp->next;
    }
    else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nProduct deleted successfully!\n";

    saveProducts();
}

// Sort products by price
void sortByPrice() {
    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.price > j->next->data.price) {
                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by price successfully!\n";

    displayProducts();
}

// Sort products by ID
void sortByID() {
    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.id > j->next->data.id) {
                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by ID successfully!\n";

    displayProducts();
}

// Sort products by name
void sortByName() {

    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {

        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.name > j->next->data.name) {

                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by name successfully!\n";

    displayProducts();
}

// Sort products by category
void sortByCategory() {

    if (head == NULL || head->next == NULL) {
        cout << "\nNot enough products to sort!\n";
        return;
    }

    for (Node* i = head; i->next != NULL; i = i->next) {

        for (Node* j = head; j->next != NULL; j = j->next) {

            if (j->data.category > j->next->data.category) {

                Product temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }

    cout << "\nProducts sorted by category successfully!\n";

    displayProducts();
}

// Add product to cart
void addToCart() {
    int id, qty;

    cout << "\nEnter Product ID: ";
    cin >> id;

    Node* product = searchProduct(id);

    if (product == NULL) {
        cout << "\nProduct not found!\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> qty;

    if (qty <= 0) {
        cout << "\nInvalid quantity!\n";
        return;
    }

    CartNode* temp = cartHead;

    while (temp != NULL) {
        if (temp->id == id) {
            if (temp->quantity + qty > product->data.quantity) {
                cout << "\nNot enough stock available!\n";
                return;
            }

            temp->quantity += qty;
            cout << "\nCart quantity updated successfully!\n";
            return;
        }

        temp = temp->next;
    }

    if (qty > product->data.quantity) {
        cout << "\nNot enough stock available!\n";
        return;
    }

    CartNode* newNode = new CartNode;

    newNode->id = product->data.id;
    newNode->name = product->data.name;
    newNode->price = product->data.price;
    newNode->quantity = qty;
    newNode->next = NULL;

    if (cartHead == NULL) {
        cartHead = newNode;
    } else {
        temp = cartHead;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nProduct added to cart successfully!\n";
}

// Display shopping cart
void displayCart() {
    if (cartHead == NULL) {
        cout << "\nYour cart is empty!\n";
        return;
    }

    CartNode* temp = cartHead;
    double total = 0;

    cout << "\n========== SHOPPING CART ==========\n";

    while (temp != NULL) {
        double subtotal = temp->price * temp->quantity;

        cout << "\nProduct ID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nPrice: " << temp->price;
        cout << "\nQuantity: " << temp->quantity;
        cout << "\nSubtotal: " << subtotal << endl;

        total += subtotal;
        temp = temp->next;
    }

    cout << "\n-----------------------------------";
    cout << "\nGrand Total: " << total << endl;
}

// Remove product from cart
void removeFromCart() {
    if (cartHead == NULL) {
        cout << "\nYour cart is empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Product ID to remove: ";
    cin >> id;

    CartNode* temp = cartHead;
    CartNode* previous = NULL;

    while (temp != NULL && temp->id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\nProduct not found in cart!\n";
        return;
    }

    if (previous == NULL) {
        cartHead = temp->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "\nProduct removed from cart successfully!\n";
}

// Save orders into a file
void saveOrders() {

    ofstream file("orders.txt");

    Order* temp = front;

    while (temp != NULL) {

        int count = 0;
        CartNode* item = temp->items;

        // Count products in this order
        while (item != NULL) {
            count++;
            item = item->next;
        }

        // Save order information
        file << temp->orderID << " "
             << temp->total << " "
             << count << endl;

        // Save ordered products
        item = temp->items;

        while (item != NULL) {

            file << item->id << " "
                 << item->name << " "
                 << item->price << " "
                 << item->quantity << endl;

            item = item->next;
        }

        temp = temp->next;
    }

    file.close();

    cout << "\nOrders saved successfully!\n";
}

//  Load orders from a file
void loadOrders() {
    ifstream file("orders.txt");

    if (!file) {
        return;
    }

    while (true) {
        Order* newOrder = new Order;
        int count;

        if (!(file >> newOrder->orderID
                  >> newOrder->total
                  >> count)) {
            delete newOrder;
            break;
        }

        newOrder->items = NULL;
        newOrder->next = NULL;

        CartNode* itemTail = NULL;

        for (int i = 0; i < count; i++) {
            CartNode* newItem = new CartNode;

            file >> newItem->id
                 >> newItem->name
                 >> newItem->price
                 >> newItem->quantity;

            newItem->next = NULL;

            if (newOrder->items == NULL) {
                newOrder->items = newItem;
            } else {
                itemTail->next = newItem;
            }

            itemTail = newItem;
        }

        if (front == NULL) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }

        if (newOrder->orderID >= nextOrderID) {
            nextOrderID = newOrder->orderID + 1;
        }
    }

    file.close();

    cout << "\nOrders loaded successfully!\n";
}

// Save the next order ID to the file
void saveNextOrderID() {
    ofstream file("order_counter.txt");

    file << nextOrderID;

    file.close();
}

// Load the next order ID from the file
void loadNextOrderID() {
    ifstream file("order_counter.txt");

    if (file) {
        file >> nextOrderID;
    }

    file.close();
}

// Place order
void placeOrder() {

    if (cartHead == NULL) {
        cout << "\nYour cart is empty! Cannot place order.\n";
        return;
    }

    // STEP 1: Validate stock for ALL cart items
    CartNode* cartTemp = cartHead;

    while (cartTemp != NULL) {

        Node* product = searchProduct(cartTemp->id);

        if (product == NULL) {
            cout << "\nError! Product no longer exists.\n";
            return;
        }

        if (cartTemp->quantity <= 0 ||
            product->data.quantity < cartTemp->quantity) {

            cout << "\nError! Not enough stock for "
                 << cartTemp->name << endl;

            return;
        }

        cartTemp = cartTemp->next;
    }

    // STEP 2: Create new order
    Order* newOrder = new Order;

    newOrder->orderID = nextOrderID++;
    saveNextOrderID();
    newOrder->total = 0;
    newOrder->items = NULL;
    newOrder->next = NULL;

    cartTemp = cartHead;
    CartNode* itemTail = NULL;

    // STEP 3: Copy cart items and calculate total
    while (cartTemp != NULL) {

        CartNode* newItem = new CartNode;

        newItem->id = cartTemp->id;
        newItem->name = cartTemp->name;
        newItem->price = cartTemp->price;
        newItem->quantity = cartTemp->quantity;
        newItem->next = NULL;

        if (newOrder->items == NULL) {
            newOrder->items = newItem;
        } else {
            itemTail->next = newItem;
        }

        itemTail = newItem;

        newOrder->total +=
            cartTemp->price * cartTemp->quantity;

        // Deduct stock only after validation
        Node* product = searchProduct(cartTemp->id);

        product->data.quantity -= cartTemp->quantity;

        cartTemp = cartTemp->next;
    }

    // STEP 4: Add order to queue
    if (front == NULL) {
        front = rear = newOrder;
    } else {
        rear->next = newOrder;
        rear = newOrder;
    }

    // STEP 5: Display confirmation
    cout << "\nOrder placed successfully!";
    cout << "\nOrder ID: " << newOrder->orderID;
    cout << "\nTotal Amount: " << newOrder->total << endl;

    // STEP 6: Clear shopping cart
    while (cartHead != NULL) {
        CartNode* temp = cartHead;
        cartHead = cartHead->next;
        delete temp;
    }

    saveProducts();

    saveOrders();
}

// Process order
void processOrder() {
    if (front == NULL) {
        cout << "\nNo pending orders to process!\n";
        return;
    }

    Order* temp = front;

    cout << "\n========== PROCESSING ORDER ==========\n";
    cout << "Order ID: " << temp->orderID;
    cout << "\nTotal Amount: " << temp->total << endl;

    CartNode* item = temp->items;

    cout << "\nOrdered Products:\n";

    while (item != NULL) {
        cout << item->name
             << " | Quantity: " << item->quantity
             << " | Price: " << item->price << endl;

        item = item->next;
    }

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    item = temp->items;

    while (item != NULL) {
        CartNode* deleteItem = item;
        item = item->next;
        delete deleteItem;
    }

    delete temp;

    cout << "\nOrder processed successfully!\n";

    saveOrders();
}

// Display all pending orders
void displayOrders() {
    if (front == NULL) {
        cout << "\nNo pending orders!\n";
        return;
    }

    Order* temp = front;

    cout << "\n========== PENDING ORDERS ==========\n";

    while (temp != NULL) {
        cout << "\nOrder ID: " << temp->orderID;
        cout << "\nTotal Amount: " << temp->total;

        CartNode* item = temp->items;

        cout << "\nOrdered Products:\n";

        while (item != NULL) {
            cout << item->name
                 << " | Quantity: " << item->quantity
                 << " | Price: " << item->price << endl;

            item = item->next;
        }

        cout << "-----------------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    loadProducts();

    loadNextOrderID();

    loadOrders();

    do
    {      
        cout << "\n===== ONLINE SHOPPING SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product by ID\n";
        cout << "4. Search Product by Name\n";
        cout << "5. Search Product by Category\n";
        cout << "6. Search Product by Price\n";
        cout << "7. Update Product\n";
        cout << "8. Delete Product\n";
        cout << "9. Sort Products by Name\n";
        cout << "10. Sort Products by Price\n";
        cout << "11. Sort Products by ID\n";
        cout << "12. Sort Products by Category\n";
        cout << "13. Add Product to Cart\n";
        cout << "14. Display Shopping Cart\n";
        cout << "15. Remove Product from Cart\n";
        cout << "16. Place Order\n";
        cout << "17. Process Order\n";
        cout << "18. Display Pending Orders\n";
        cout << "19. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;


        
        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProductMenu();
                break;

            case 4:
                searchProductByName();
                break;

            case 5:
                searchProductByCategory();
                break;

            case 6:
                searchProductByPrice();
                break;

            case 7:
                updateProduct();
                break;

            case 8:
                deleteProduct();
                break;

            case 9:
                sortByName();
                break;

            case 10:
                sortByPrice();
                break;

            case 11:
                sortByID();
                break;

            case 12:
                sortByCategory();
                break;

            case 13:
                addToCart();
                break;

            case 14:
                displayCart();
                break;

            case 15:
                removeFromCart();
                break;

            case 16:
                placeOrder();
                break;

            case 17:
                processOrder();
                break;

            case 18:
                displayOrders();
                break;

            case 19:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 19);

    return 0;
}
