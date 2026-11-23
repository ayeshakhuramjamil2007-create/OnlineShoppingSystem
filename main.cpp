#include <iostream>
#include "order.h"
using namespace std;

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
