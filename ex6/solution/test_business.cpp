/****************************************
 Standalone test driver for BusinessCustomer
 Tests: discount math, cart clear, supplier profit accounting
*****************************************/

#include "Product.h"
#include "ShoppingCart.h"
#include "Supplier.h"
#include "Customer.h"
#include <iostream>
#include <cassert>

using namespace std;

static void separator(const string &label) {
    cout << "\n========== " << label << " ==========" << endl;
}

int main() {
    // ---- Test A: BusinessCustomer discount applied at checkout ----
    separator("A: BusinessCustomer 20% discount");

    Product apple("Apple", 2.0, 10);
    Product banana("Banana", 1.0, 5);

    Supplier s;
    s.add_Product(apple, 10);   // counter: 0 - 20 = -20
    s.add_Product(banana, 5);   // counter: -20 - 5 = -25

    BusinessCustomer bc("Tomer", "TechCorp", 0.2);
    bc.add_to_cart(apple, 3);   // 3 * 2.0 = 6.0
    bc.add_to_cart(banana, 2);  // 2 * 1.0 = 2.0
    // full cart total: 8.0 | after 20% discount: 6.4

    cout << "[Cart total before checkout] " << bc.get_cart().Get_total() << " (expect 8)" << endl;

    // supplier records FULL cart price (not discounted)
    s.customer_purchases(bc.get_cart());
    cout << "[Supplier profit after customer_purchases] " << s.get_total_profit()
         << " (expect -17: -25 + 8)" << endl;

    // checkout() should print discounted total, then cart, then clear
    cout << "\n--- checkout() output below ---" << endl;
    double returned = bc.checkout();
    cout << "--- end checkout() output ---" << endl;

    cout << "[checkout() returned] " << returned << " (expect 6.4)" << endl;
    cout << "[Cart total after checkout] " << bc.get_cart().Get_total() << " (expect 0)" << endl;

    // ---- Test B: supplier profit uses full price, not discounted ----
    separator("B: supplier profit uses full cart price");
    // Already verified above: counter = -17 (from full 8.0, not discounted 6.4)
    // If it used the discounted total instead it would be -25 + 6.4 = -18.6
    cout << "[Final supplier profit] " << s.get_total_profit()
         << " (expect -17 if full price; -18.6 if discounted)" << endl;

    // ---- Test C: re-checkout after cart cleared ----
    separator("C: checkout on empty cart");
    double empty_total = bc.get_cart().Get_total();
    cout << "[Cart total] " << empty_total << " (expect 0)" << endl;
    s.customer_purchases(bc.get_cart()); // processes empty cart — should not crash
    double empty_checkout = bc.checkout();
    cout << "[Empty checkout returned] " << empty_checkout << " (expect 0)" << endl;

    // ---- Test D: zero discount rate ----
    separator("D: BusinessCustomer 0% discount (no discount)");
    Product milk("Milk", 3.0, 20);
    s.add_Product(milk, 20);

    BusinessCustomer bc2("Carmi", "StartupCo", 0.0);
    bc2.add_to_cart(milk, 4); // 4 * 3.0 = 12.0
    cout << "[Cart total] " << bc2.get_cart().Get_total() << " (expect 12)" << endl;
    s.customer_purchases(bc2.get_cart());
    double zero_disc = bc2.checkout();
    cout << "[checkout() returned] " << zero_disc << " (expect 12: 0% discount)" << endl;

    // ---- Test E: 100% discount rate ----
    separator("E: BusinessCustomer 100% discount (free)");
    Product candy("Candy", 5.0, 10);
    s.add_Product(candy, 10);

    BusinessCustomer bc3("VIP", "MegaCorp", 1.0);
    bc3.add_to_cart(candy, 2); // 2 * 5.0 = 10.0
    cout << "[Cart total] " << bc3.get_cart().Get_total() << " (expect 10)" << endl;
    s.customer_purchases(bc3.get_cart());
    double full_disc = bc3.checkout();
    cout << "[checkout() returned] " << full_disc << " (expect 0: 100% discount)" << endl;

    return 0;
}
