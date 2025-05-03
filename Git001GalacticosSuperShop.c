/*
 * GALACTICOs Super Shop Management System
 * GitHub: https://github.com/mehedyk  Author: S. M. Mehedy Kawser
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// -------------------------Data Structures -------------------------
struct Product {
    char name[100];
    float price;
    int quantity;
    int totalSoldQuantity;
    float totalSales;
    float discount;
};

struct Employee {
    char name[100];
    float salary;
    int age;
    char username[100];
    char password[100];
    float bonus;
    int isAdmin; //1 admin, 0 employee
};

struct Customer {
    char name[100];
    char username[100];
    char password[100];
};

// -------------------------Global Arrays and Variables -------------------------
struct Product products[MAX];
int productCount = 0;

struct Employee employees[MAX];
int employeeCount = 0;

struct Customer customers[MAX];
int customerCount = 0;

float storeDiscount = 0;

float employeeSalesTotal = 0;
float customerSalesTotal = 0;

// ------------------------- utility Functions -------------------------
void GALACTICOs() {
    printf("\n\t\t\t\t\t\t_____________________\n");
    printf("\t\t\t\t\t\tGALACTICOs Super Shop\n");
    printf("\t\t\t\t\t\t\tG.S.S.\n");
    printf("\t\t\t\t\t\t_____________________\n");
}

void contactUs() {
    printf("\n\n\t\t\t\t\t\t----Contact Us----\n");
    printf("\t\t\t\t\t\tPhone: 01*********\n");
    printf("\t\t\t\t\t\tAddress: GALACTICOs Super Shop, Chilling Zone, Dhaka-9999\n");
    printf("\t\t\t\t\t\tFacebook: fb.com/galacticosshopbd\n");
    printf("\t\t\t\t\t\t[**Infos are fictional]\n");
}

void openingTime() {
    printf("\n\n\t\t\t\t\t\t----Opening Time----\n");
    printf("\t\t\t\t\t\t8:00 AM\n");
    printf("\n\t\t\t\t\t\t----Break Time----\n");
    printf("\t\t\t\t\t\t12:50 PM -- 1:50 PM\n");
    printf("\n\t\t\t\t\t\t----Closing Time----\n");
    printf("\t\t\t\t\t\t11:00 PM\n");
}

// ------------------------- product Functions -------------------------
int pushProduct(struct Product item) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, item.name) == 0) {
            printf("\n\t\t\t\t\t\tProduct already exists!\n");
            return 0;
        }
    }
    if (productCount < MAX) {
        if (item.price < 0 || item.quantity < 0 || item.discount < 0) {
            printf("\n\t\t\t\t\t\tInvalid product details! Price, quantity, and discount must be non-negative.\n");
            return 0;
        }
        item.totalSoldQuantity = 0;
        item.totalSales = 0;
        products[productCount++] = item;
        return 1;
    } else {
        printf("\n\t\t\t\t\t\tMemory Full, No space!\n");
        return 0;
    }
}

void displayProducts() {
    if (productCount > 0) {
        printf("\n\t\t\t\t\t\tStock Contents:\n");
        for (int i = 0; i < productCount; i++) {
            printf("\n\t\t\t\t\t\t%d: Name: %s, Price: %.2f, Quantity: %d, Discount: %.2f%%",
                   i + 1, products[i].name, products[i].price, products[i].quantity, products[i].discount);
        }
        printf("\n");
    } else {
        printf("\n\t\t\t\t\t\tStock is empty!\n");
    }
}

void deleteProductByName() {
    char productName[100];
    printf("\n\t\t\t\t\t\tEnter the name of the product to delete: ");
    scanf(" %99[^\n]", productName);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("\n\t\t\t\t\t\tDeleted product '%s'\n", productName);
            break;
        }
    }
    if (!found) {
        printf("\n\t\t\t\t\t\tProduct '%s' not found in stock\n", productName);
    }
}

// ------------------------- Sales Functions -------------------------
//employee er
void sellProduct() {
    char productName[100];
    int quantity;
    printf("\n\t\t\t\t\t\tEnter the name of the product to sell: ");
    scanf(" %99[^\n]", productName);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            found = 1;
            printf("\n\t\t\t\t\t\tEnter the quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= 0) {
                printf("\n\t\t\t\t\t\tInvalid quantity.\n");
                return;
            }
            if (quantity <= products[i].quantity) {
                products[i].quantity -= quantity;
                float totalCost = quantity * products[i].price * (1 - storeDiscount / 100);
                products[i].totalSoldQuantity += quantity;
                products[i].totalSales += totalCost;
                employeeSalesTotal += totalCost;
                printf("\n\t\t\t\t\t\tSold %d units of %s successfully.\n", quantity, products[i].name);
                printf("\n\t\t\t\t\t\t--Bill--\n");
                printf("\n\t\t\t\t\t\tProduct: %s", products[i].name);
                printf("\n\t\t\t\t\t\tQuantity: %d", quantity);
                printf("\n\t\t\t\t\t\tPrice per unit: %.2f", products[i].price);
                printf("\n\t\t\t\t\t\tStore Discount: %.2f%%", storeDiscount);
                printf("\n\t\t\t\t\t\tTotal cost after discount: %.2f\n", totalCost);
            } else {
                printf("\n\t\t\t\t\t\tNot enough quantity of %s in stock.\n", products[i].name);
            }
            break;
        }
    }
    if (!found) {
        printf("\n\t\t\t\t\t\tProduct '%s' not found in stock.\n", productName);
    }
}

//customer er
void buyProduct() {
    char productName[100];
    int quantity;
    printf("\n\t\t\t\t\t\tEnter the name of the product to buy: ");
    scanf(" %99[^\n]", productName);
    
    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].name, productName) == 0) {
            found = 1;
            printf("\n\t\t\t\t\t\tEnter the quantity to buy: ");
            scanf("%d", &quantity);
            if (quantity <= 0) {
                printf("\n\t\t\t\t\t\tInvalid quantity.\n");
                return;
            }
            if (quantity <= products[i].quantity) {
                products[i].quantity -= quantity;
                float totalCost = quantity * products[i].price * (1 - products[i].discount / 100);
                products[i].totalSoldQuantity += quantity;
                products[i].totalSales += totalCost;
                customerSalesTotal += totalCost;
                printf("\n\t\t\t\t\t\tPurchased %d units of %s successfully.\n", quantity, products[i].name);
                printf("\n\t\t\t\t\t\t--Bill--\n");
                printf("\n\t\t\t\t\t\tProduct: %s", products[i].name);
                printf("\n\t\t\t\t\t\tQuantity: %d", quantity);
                printf("\n\t\t\t\t\t\tPrice per unit: %.2f", products[i].price);
                printf("\n\t\t\t\t\t\tProduct Discount: %.2f%%", products[i].discount);
                printf("\n\t\t\t\t\t\tTotal cost after discount: %.2f\n", totalCost);
            } else {
                printf("\n\t\t\t\t\t\tNot enough quantity of %s in stock.\n", products[i].name);
            }
            break;
        }
    }
    if (!found) {
        printf("\n\t\t\t\t\t\tProduct '%s' not found in stock.\n", productName);
    }
}

// -------------------------employee Functions -------------------------
int addEmployee(struct Employee item) {
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].username, item.username) == 0) {
            printf("\n\t\t\t\t\t\tEmployee username already exists!\n");
            return 0;
        }
    }
    if (employeeCount < MAX) {
        employees[employeeCount++] = item;
        return 1;
    } else {
        printf("\n\t\t\t\t\t\tMemory Full, No space!\n");
        return 0;
    }
}

void deleteEmployeeByName() {
    char employeeName[100];
    printf("\n\t\t\t\t\t\tEnter the name of the employee to delete: ");
    scanf(" %99[^\n]", employeeName);
    
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employees[i].name, employeeName) == 0) {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("\n\t\t\t\t\t\tDeleted employee '%s'\n", employeeName);
            break;
        }
    }
    if (!found) {
        printf("\n\t\t\t\t\t\tEmployee '%s' not found!\n", employeeName);
    }
}

void displayEmployees() {
    if (employeeCount > 0) {
        printf("\n\t\t\t\t\t\tEmployees List:\n");
        for (int i = 0; i < employeeCount; i++) {
            printf("\n\t\t\t\t\t\t%d: Name: %s, Salary: %.2f, Salary with Bonus: %.2f, Age: %d, Username: %s, Bonus: %.2f, Role: %s",
                   i + 1, employees[i].name, employees[i].salary, employees[i].salary + employees[i].bonus,
                   employees[i].age, employees[i].username, employees[i].bonus,
                   (employees[i].isAdmin ? "Admin" : "Employee"));
        }
        printf("\n");
    } else {
        printf("\n\t\t\t\t\t\tNo employees found.\n");
    }
}

void addAdmin() {
    struct Employee newAdmin;
    printf("\n\t\t\t\t\t\tEnter admin name: ");
    scanf(" %99[^\n]", newAdmin.name);
    printf("\n\t\t\t\t\t\tEnter admin salary: ");
    scanf("%f", &newAdmin.salary);
    while(newAdmin.salary < 0) {
        printf("\n\t\t\t\t\t\tSalary must be positive. Enter again: ");
        scanf("%f", &newAdmin.salary);
    }
    printf("\n\t\t\t\t\t\tEnter admin age: ");
    scanf("%d", &newAdmin.age);
    while(newAdmin.age <= 0) {
        printf("\n\t\t\t\t\t\tAge must be positive. Enter again: ");
        scanf("%d", &newAdmin.age);
    }
    printf("\n\t\t\t\t\t\tEnter admin username: ");
    scanf(" %99[^\n]", newAdmin.username);
    printf("\n\t\t\t\t\t\tEnter admin password: ");
    scanf(" %99[^\n]", newAdmin.password);
    newAdmin.bonus = 0;
    newAdmin.isAdmin = 1;
    if(addEmployee(newAdmin))
        printf("\n\t\t\t\t\t\tAdmin added successfully!\n");
}

// ------------------------- Customer Functions -------------------------
int addCustomer(struct Customer item) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].username, item.username) == 0) {
            printf("\n\t\t\t\t\t\tCustomer username already exists!\n");
            return 0;
        }
    }
    if (customerCount < MAX) {
        customers[customerCount++] = item;
        return 1;
    } else {
        printf("\n\t\t\t\t\t\tMemory Full, No space!\n");
        return 0;
    }
}

void displayCustomers() {
    if (customerCount > 0) {
        printf("\n\t\t\t\t\t\tCustomers List:\n");
        for (int i = 0; i < customerCount; i++) {
            printf("\n\t\t\t\t\t\t%d: Name: %s, Username: %s",
                   i + 1, customers[i].name, customers[i].username);
        }
        printf("\n");
    } else {
        printf("\n\t\t\t\t\t\tNo customers registered.\n");
    }
}

// ------------------------- Registration Functions -------------------------
void registerEmployee() {
    struct Employee newEmp;
    printf("\n\t\t\t\t\t\tEnter employee name: ");
    scanf(" %99[^\n]", newEmp.name);
    printf("\n\t\t\t\t\t\tEnter employee salary: ");
    scanf("%f", &newEmp.salary);
    while(newEmp.salary < 0) {
        printf("\n\t\t\t\t\t\tSalary must be positive. Enter again: ");
        scanf("%f", &newEmp.salary);
    }
    printf("\n\t\t\t\t\t\tEnter employee age: ");
    scanf("%d", &newEmp.age);
    while(newEmp.age <= 0) {
        printf("\n\t\t\t\t\t\tAge must be positive. Enter again: ");
        scanf("%d", &newEmp.age);
    }
    printf("\n\t\t\t\t\t\tEnter employee username: ");
    scanf(" %99[^\n]", newEmp.username);
    printf("\n\t\t\t\t\t\tEnter employee password: ");
    scanf(" %99[^\n]", newEmp.password);
    newEmp.bonus = 0;
    newEmp.isAdmin = 0;
    if(addEmployee(newEmp))
        printf("\n\t\t\t\t\t\tEmployee registration successful!\n");
}

void registerCustomer() {
    struct Customer newCust;
    printf("\n\t\t\t\t\t\tEnter customer name: ");
    scanf(" %99[^\n]", newCust.name);
    printf("\n\t\t\t\t\t\tEnter customer username: ");
    scanf(" %99[^\n]", newCust.username);
    printf("\n\t\t\t\t\t\tEnter customer password: ");
    scanf(" %99[^\n]", newCust.password);
    if(addCustomer(newCust))
        printf("\n\t\t\t\t\t\tCustomer registration successful!\n");
}

// ------------------------- Login Functions -------------------------
int loginAdmin() {
    char username[100], password[100];
    printf("\n\t\t\t\t\t\tEnter admin username: ");
    scanf(" %99[^\n]", username);
    printf("\n\t\t\t\t\t\tEnter password: ");
    scanf(" %99[^\n]", password);
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].isAdmin && strcmp(employees[i].username, username) == 0 && strcmp(employees[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int loginEmployee() {
    char username[100], password[100];
    printf("\n\t\t\t\t\t\tEnter employee username: ");
    scanf(" %99[^\n]", username);
    printf("\n\t\t\t\t\t\tEnter password: ");
    scanf(" %99[^\n]", password);
    for (int i = 0; i < employeeCount; i++) {
        if (!employees[i].isAdmin && strcmp(employees[i].username, username) == 0 && strcmp(employees[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

int loginCustomer() {
    char username[100], password[100];
    printf("\n\t\t\t\t\t\tEnter customer username: ");
    scanf(" %99[^\n]", username);
    printf("\n\t\t\t\t\t\tEnter password: ");
    scanf(" %99[^\n]", password);
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].username, username) == 0 && strcmp(customers[i].password, password) == 0) {
            return i;
        }
    }
    return -1;
}

// ------------------------- Admin Functions -------------------------
void setStoreDiscount() {
    printf("\n\t\t\t\t\t\tEnter Eid discount percentage: ");
    scanf("%f", &storeDiscount);
    if (storeDiscount < 0) {
        storeDiscount = 0;
        printf("\n\t\t\t\t\t\tDiscount cannot be negative. Set to 0.\n");
    } else {
        printf("\n\t\t\t\t\t\tEid discount set to %.2f%%\n", storeDiscount);
    }
}

void setEmployeeBonus() {
    int index;
    printf("\n\t\t\t\t\t\tEnter employee index to set Eid bonus: ");
    scanf("%d", &index);
    if (index < 1 || index > employeeCount) {
        printf("\n\t\t\t\t\t\tInvalid employee index\n");
        return;
    }
    if (employees[index - 1].isAdmin) {
        printf("\n\t\t\t\t\t\tCannot set bonus for admin.\n");
        return;
    }
    float bonus;
    printf("\n\t\t\t\t\t\tEnter Eid bonus for employee '%s': ", employees[index - 1].name);
    scanf("%f", &bonus);
    if (bonus < 0) {
        printf("\n\t\t\t\t\t\tBonus cannot be negative. Setting to 0.\n");
        bonus = 0;
    }
    employees[index - 1].bonus = bonus;
    printf("\n\t\t\t\t\t\tEid bonus set for employee '%s': %.2f\n", employees[index - 1].name, bonus);
}

void salesReport() {
    float grandTotal = employeeSalesTotal + customerSalesTotal;
    printf("\n\t\t\t\t\t\t--------- Sales Report ---------\n");
    printf("\n\t\t\t\t\t\tEmployee Sales Total: %.2f", employeeSalesTotal);
    printf("\n\t\t\t\t\t\tCustomer Sales Total: %.2f", customerSalesTotal);
    printf("\n\t\t\t\t\t\tGrand Total Sales: %.2f\n", grandTotal);
}

int main() {
    system("color 0A");
    GALACTICOs();

    pushProduct((struct Product){"Rice", 600, 100, 0, 0, 0});
    pushProduct((struct Product){"Chips", 20, 200, 0, 0, 0});
    pushProduct((struct Product){"Biscuit", 15, 200, 0, 0, 0});
    pushProduct((struct Product){"Shampoo", 350, 100, 0, 0, 0});
    pushProduct((struct Product){"Soap", 55, 100, 0, 0, 0});
    pushProduct((struct Product){"Juice", 20, 200, 0, 0, 0});
    pushProduct((struct Product){"Soybean", 550, 100, 0, 0, 0});
    pushProduct((struct Product){"Spices", 200, 300, 0, 0, 0});
    pushProduct((struct Product){"Cleaner", 230, 100, 0, 0, 0});
    pushProduct((struct Product){"Clothes", 500, 150, 0, 0, 0});

    struct Employee emp0 = {"Mehedy", 50000, 21, "mehedyceo", "1202", 0, 1};
    addEmployee(emp0);
    struct Employee emp1 = {"Admin", 50000, 21, "admin", "1234", 0, 1};
    addEmployee(emp1);

    struct Customer cust0 = {"Rakib", "rakib", "1234"};
    addCustomer(cust0);
    struct Customer cust1 = {"Rahat", "rahat", "1234"};
    addCustomer(cust1);
    struct Customer cust2 = {"Rafi", "rafi", "1234"};
    addCustomer(cust2);
    struct Customer cust3 = {"Rahi", "rahi", "1234"};
    addCustomer(cust3);
    struct Customer cust4 = {"Rahim", "rahim", "1234"};
    addCustomer(cust4);
    struct Customer cust5 = {"Rahman", "rahman", "1234"};
    addCustomer(cust5);
    struct Customer cust6 = {"Rony", "rony", "1234"};
    addCustomer(cust6);
    struct Customer cust7 = {"Rasel", "rasel", "1234"};
    addCustomer(cust7);
    struct Customer cust8 = {"Ratul", "ratul", "1234"};
    addCustomer(cust8);

    int mainChoice;
    int currentUserIndex = -1;
    int currentUserRole = 0; // 1 = admin, 2 = employee, 3 = customer

    while (1) {
        printf("\n\t\t\t\t\t\tMain Menu:\n");
        printf("\t\t\t\t\t\t1. Login\n");
        printf("\t\t\t\t\t\t2. Register\n");
        printf("\t\t\t\t\t\t3. Operating Time\n");
        printf("\t\t\t\t\t\t4. Contact Us\n");
        printf("\t\t\t\t\t\t0. Exit\n");
        printf("\t\t\t\t\t\tYour choice: ");
        scanf("%d", &mainChoice);
        
        if (mainChoice == 0) {
            printf("\n\t\t\t\t\t\tExiting...Shop again!\n");
            break;
        } else if (mainChoice == 1) {
            int roleChoice;
            printf("\n\t\t\t\t\t\tLogin as:\n");
            printf("\t\t\t\t\t\t1. Admin\n");
            printf("\t\t\t\t\t\t2. Employee\n");
            printf("\t\t\t\t\t\t3. Customer\n");
            printf("\t\t\t\t\t\tYour choice: ");
            scanf("%d", &roleChoice);
            if (roleChoice == 1) {
                int idx = loginAdmin();
                if (idx != -1) {
                    currentUserIndex = idx;
                    currentUserRole = 1;
                    printf("\n\t\t\t\t\t\tAdmin login successful!\n");
                } else {
                    printf("\n\t\t\t\t\t\tInvalid admin credentials.\n");
                    continue;
                }
            } else if (roleChoice == 2) {
                int idx = loginEmployee();
                if (idx != -1) {
                    currentUserIndex = idx;
                    currentUserRole = 2;
                    printf("\n\t\t\t\t\t\tEmployee login successful!\n");
                } else {
                    printf("\n\t\t\t\t\t\tInvalid employee credentials.\n");
                    continue;
                }
            } else if (roleChoice == 3) {
                int idx = loginCustomer();
                if (idx != -1) {
                    currentUserIndex = idx;
                    currentUserRole = 3;
                    printf("\n\t\t\t\t\t\tCustomer login successful!\n");
                } else {
                    printf("\n\t\t\t\t\t\tInvalid customer credentials.\n");
                    continue;
                }
            } else {
                printf("\n\t\t\t\t\t\tInvalid choice.\n");
                continue;
            }
            
            // -------------------------- Admin Menu ---------------------------
            if (currentUserRole == 1) {
                int adminChoice;
                while (1) {
                    printf("\n\t\t\t\t\t\tAdmin Menu:\n");
                    printf("\t\t\t\t\t\t1. Set Eid Discount\n");
                    printf("\t\t\t\t\t\t2. Set Employee Eid Bonus\n");
                    printf("\t\t\t\t\t\t3. Delete Employee by Name\n");
                    printf("\t\t\t\t\t\t4. Display Employees\n");
                    printf("\t\t\t\t\t\t5. Add Admin\n");
                    printf("\t\t\t\t\t\t6. Display Customers\n");
                    printf("\t\t\t\t\t\t7. Display Products\n");
                    printf("\t\t\t\t\t\t8. Sales Report\n");
                    printf("\t\t\t\t\t\t0. Logout\n");
                    printf("\t\t\t\t\t\tYour choice: ");
                    scanf("%d", &adminChoice);
                    
                    if (adminChoice == 0) {
                        printf("\n\t\t\t\t\t\tLogging out...\n");
                        currentUserIndex = -1;
                        currentUserRole = 0;
                        break;
                    }
                    
                    switch (adminChoice) {
                        case 1: setStoreDiscount(); break;
                        case 2: setEmployeeBonus(); break;
                        case 3: deleteEmployeeByName(); break;
                        case 4: displayEmployees(); break;
                        case 5: addAdmin(); break;
                        case 6: displayCustomers(); break;
                        case 7: displayProducts(); break;
                        case 8: salesReport(); break;
                        default: printf("\n\t\t\t\t\t\tInvalid choice.\n"); break;
                    }
                }
            // -------------------------- Employee Menu ---------------------------
            } else if (currentUserRole == 2) {
                int empChoice;
                while (1) {
                    printf("\n\t\t\t\t\t\tEmployee Menu:\n");
                    printf("\t\t\t\t\t\t1. Sell a Product\n");
                    printf("\t\t\t\t\t\t2. Delete a Product by Name\n");
                    printf("\t\t\t\t\t\t3. Display Products\n");
                    printf("\t\t\t\t\t\t4. Display Customers\n");
                    printf("\t\t\t\t\t\t5. Operating Time\n");
                    printf("\t\t\t\t\t\t0. Logout\n");
                    printf("\t\t\t\t\t\tYour choice: ");
                    scanf("%d", &empChoice);
                    
                    if (empChoice == 0) {
                        printf("\n\t\t\t\t\t\tLogging out...\n");
                        currentUserIndex = -1;
                        currentUserRole = 0;
                        break;
                    }
                    
                    switch (empChoice) {
                        case 1: sellProduct(); break;
                        case 2: deleteProductByName(); break;
                        case 3: displayProducts(); break;
                        case 4: displayCustomers(); break;
                        case 5: openingTime(); break;
                        default: printf("\n\t\t\t\t\t\tInvalid choice.\n"); break;
                    }
                }
            // -------------------------- Customer Menu ---------------------------
            } else if (currentUserRole == 3) {
                int custChoice;
                while (1) {
                    printf("\n\t\t\t\t\t\tCustomer Menu:\n");
                    printf("\t\t\t\t\t\t1. Buy a Product\n");
                    printf("\t\t\t\t\t\t2. Display Products\n");
                    printf("\t\t\t\t\t\t3. Operating Time\n");
                    printf("\t\t\t\t\t\t4. Contact Us\n");
                    printf("\t\t\t\t\t\t0. Logout\n");
                    printf("\t\t\t\t\t\tYour choice: ");
                    scanf("%d", &custChoice);
                    
                    if (custChoice == 0) {
                        printf("\n\t\t\t\t\t\tLogging out...\n");
                        currentUserIndex = -1;
                        currentUserRole = 0;
                        break;
                    }
                    
                    switch (custChoice) {
                        case 1: buyProduct(); break;
                        case 2: displayProducts(); break;
                        case 3: openingTime(); break;
                        case 4: contactUs(); break;
                        default: printf("\n\t\t\t\t\t\tInvalid choice.\n"); break;
                    }
                }
            }
        } else if (mainChoice == 2) {
            int regChoice;
            printf("\n\t\t\t\t\t\tRegister as:\n");
            printf("\t\t\t\t\t\t1. Employee\n");
            printf("\t\t\t\t\t\t2. Customer\n");
            printf("\t\t\t\t\t\tYour choice: ");
            scanf("%d", &regChoice);
            if (regChoice == 1) {
                registerEmployee();
            } else if (regChoice == 2) {
                registerCustomer();
            } else {
                printf("\n\t\t\t\t\t\tInvalid choice.\n");
            }
        } else if (mainChoice == 3) {
            openingTime();
        } else if (mainChoice == 4) {
            contactUs();
        } else {
            printf("\n\t\t\t\t\t\tInvalid main menu choice.\n");
        }
    }
}