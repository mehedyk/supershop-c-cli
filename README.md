# 🌟 GALACTICOs Super Shop Management System 🛒

<div align="center">

![Version](https://img.shields.io/badge/version-2.0.0-blue.svg)
![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![License](https://img.shields.io/badge/license-Educational-green.svg)
![Status](https://img.shields.io/badge/status-Active-success.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20MacOS-lightgrey.svg)

**A comprehensive Command-Line Interface (CLI) based Super Shop Management System**

*Simplicity meets functionality in this beginner-friendly C application*

[🚀 Quick Start](#-quick-start) • [📚 Documentation](#-documentation) • [✨ Features](#-features) • [🤝 Contributing](#-contributing) • [📧 Contact](#-contact)

---

</div>

## 📖 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [🎭 User Roles](#-user-roles)
- [🛠️ Technologies Used](#️-technologies-used)
- [📋 Prerequisites](#-prerequisites)
- [🚀 Quick Start](#-quick-start)
- [📁 Project Structure](#-project-structure)
- [💻 Usage Guide](#-usage-guide)
- [🔐 Default Credentials](#-default-credentials)
- [🎨 Screenshots & Demos](#-screenshots--demos)
- [🏗️ Architecture](#️-architecture)
- [🔧 Configuration](#-configuration)
- [🐛 Known Issues](#-known-issues)
- [🗺️ Roadmap](#️-roadmap)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)
- [👨‍💻 Author](#-author)
- [🙏 Acknowledgments](#-acknowledgments)
- [📧 Contact](#-contact)

---

## 🎯 Overview

**GALACTICOs Super Shop Management System** is a comprehensive CLI-based application designed to manage the day-to-day operations of a retail super shop. Built with simplicity and efficiency in mind, this system provides a complete solution for managing products, employees, customers, and sales transactions.

### 🌟 What Makes It Special?

- **Beginner-Friendly**: Written with simplicity as the core principle
- **Comprehensive**: Covers all essential shop management operations
- **Role-Based Access**: Three distinct user roles with specific permissions
- **Real-Time Management**: Instant inventory and sales tracking
- **Educational**: Perfect for learning C programming and system design

---

## ✨ Features

### 🛍️ Product Management
- ✅ Add new products with price, quantity, and discount
- ✅ Display complete product inventory
- ✅ Delete products by name
- ✅ Real-time stock tracking
- ✅ Individual product discount management
- ✅ Sales history for each product

### 👥 Employee Management
- ✅ Register new employees
- ✅ Admin and employee role differentiation
- ✅ Salary and bonus management
- ✅ Employee deletion capability
- ✅ Comprehensive employee listing
- ✅ Secure login system

### 👤 Customer Management
- ✅ Customer registration system
- ✅ Secure customer login
- ✅ Customer profile management
- ✅ Purchase history tracking
- ✅ Customer listing for staff

### 💰 Sales & Billing
- ✅ Employee-initiated sales (with store discount)
- ✅ Customer purchases (with product discount)
- ✅ Automatic bill generation
- ✅ Detailed invoice display
- ✅ Comprehensive sales reporting
- ✅ Separate tracking for employee and customer sales

### 🎉 Special Features
- ✅ **Eid Discount System**: Store-wide discount management
- ✅ **Employee Bonus**: Bonus allocation for special occasions
- ✅ **Operating Hours Display**: Shop timing information
- ✅ **Contact Information**: Easy access to shop details
- ✅ **Color-Coded Interface**: Enhanced visual experience

---

## 🎭 User Roles

### 👑 Admin
**Full system access with management capabilities**

```
✓ Set store-wide Eid discounts
✓ Allocate employee bonuses
✓ Add new admin accounts
✓ Delete employees
✓ View all employees
✓ View all customers
✓ View complete product inventory
✓ Generate comprehensive sales reports
```

### 👔 Employee
**Operational staff with sales and inventory access**

```
✓ Sell products to walk-in customers
✓ Delete products from inventory
✓ View product list
✓ View customer list
✓ Check operating hours
```

### 🛍️ Customer
**Registered shoppers with purchasing capabilities**

```
✓ Browse available products
✓ Purchase products
✓ View product prices and discounts
✓ Check operating hours
✓ Access contact information
```

---

## 🛠️ Technologies Used

<div align="center">

| Technology | Purpose | Version |
|------------|---------|---------|
| ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) | Core Programming Language | C99+ |
| ![GCC](https://img.shields.io/badge/GCC-Compiler-red?style=for-the-badge) | Compilation | Any Standard Compiler |
| ![Terminal](https://img.shields.io/badge/Terminal-CLI_Interface-black?style=for-the-badge) | User Interface | Cross-Platform |

</div>

### Core Libraries Used
- `stdio.h` - Standard Input/Output
- `string.h` - String manipulation
- `stdlib.h` - Memory allocation and system commands

---

## 📋 Prerequisites

Before you begin, ensure you have the following installed:

- **C Compiler** (GCC, Clang, or MSVC)
- **Terminal/Command Prompt** access
- **Basic C programming knowledge** (for modifications)

### Platform-Specific Requirements

#### 🪟 Windows
```bash
# MinGW or MSVC compiler
# Command Prompt or PowerShell
```

#### 🐧 Linux
```bash
# GCC (usually pre-installed)
sudo apt-get install gcc  # Ubuntu/Debian
sudo yum install gcc      # RHEL/CentOS
```

#### 🍎 MacOS
```bash
# Xcode Command Line Tools
xcode-select --install
```

---

## 🚀 Quick Start

### Method 1: Standard Compilation

```bash
# Clone the repository
git clone https://github.com/mehedyk/galacticos-super-shop.git

# Navigate to project directory
cd galacticos-super-shop

# Compile the program
gcc Git001GalacticosSuperShop.c -o super_shop

# Run the application
./super_shop          # Linux/MacOS
super_shop.exe        # Windows
```

### Method 2: With Makefile (Optional)

```bash
# If Makefile is provided
make
make run
```

### Method 3: Direct Compilation & Run

```bash
# Compile and run in one go
gcc Git001GalacticosSuperShop.c -o super_shop && ./super_shop
```

---

## 📁 Project Structure

```
📦 GALACTICOs-Super-Shop
┣ 📜 Git001GalacticosSuperShop.c    # Main source code
┣ 📜 README.md                       # Project documentation
┣ 📜 LICENSE                         # License file
┣ 📜 .gitignore                      # Git ignore rules
┗ 📂 docs                            # Additional documentation
  ┣ 📜 USER_GUIDE.md                # Detailed user guide
  ┗ 📜 DEVELOPER_GUIDE.md           # Developer documentation
```

---

## 💻 Usage Guide

### 🎬 Starting the Application

When you run the application, you'll see the welcome screen:

```
_____________________
GALACTICOs Super Shop
       G.S.S.
_____________________

Main Menu:
1. Login
2. Register
3. Operating Time
4. Contact Us
0. Exit
```

### 📝 Main Menu Options

#### 1️⃣ Login
Choose your role and enter credentials:
- **Admin**: Full management access
- **Employee**: Sales and inventory management
- **Customer**: Shopping and purchase access

#### 2️⃣ Register
Create new accounts:
- **Employee Registration**: Create employee accounts
- **Customer Registration**: Register as a customer

#### 3️⃣ Operating Time
View shop opening hours and break times

#### 4️⃣ Contact Us
Access shop contact information

---

## 🔐 Default Credentials

The system comes pre-configured with default accounts for testing:

### 👑 Admin Accounts

| Username | Password | Name |
|----------|----------|------|
| `mehedyceo` | `1202` | Mehedy |
| `admin` | `1234` | Admin |

### 🛍️ Customer Accounts

| Username | Password | Name |
|----------|----------|------|
| `rakib` | `1234` | Rakib |
| `rahat` | `1234` | Rahat |
| `rafi` | `1234` | Rafi |
| `rahi` | `1234` | Rahi |
| `rahim` | `1234` | Rahim |
| `rahman` | `1234` | Rahman |
| `rony` | `1234` | Rony |
| `rasel` | `1234` | Rasel |
| `ratul` | `1234` | Ratul |

### 📦 Pre-loaded Products

| Product | Price (৳) | Quantity | Discount |
|---------|-----------|----------|----------|
| Rice | 600 | 100 | 0% |
| Chips | 20 | 200 | 0% |
| Biscuit | 15 | 200 | 0% |
| Shampoo | 350 | 100 | 0% |
| Soap | 55 | 100 | 0% |
| Juice | 20 | 200 | 0% |
| Soybean | 550 | 100 | 0% |
| Spices | 200 | 300 | 0% |
| Cleaner | 230 | 100 | 0% |
| Clothes | 500 | 150 | 0% |

---

## 🎨 Screenshots & Demos

### Main Interface
```
_____________________
GALACTICOs Super Shop
       G.S.S.
_____________________

Main Menu:
1. Login
2. Register
3. Operating Time
4. Contact Us
0. Exit
```

### Sample Bill
```
--Bill--

Product: Rice
Quantity: 2
Price per unit: 600.00
Product Discount: 5.00%
Total cost after discount: 1140.00
```

---

## 🏗️ Architecture

### Data Structures

```c
// Product Structure
struct Product {
    char name[100];
    float price;
    int quantity;
    int totalSoldQuantity;
    float totalSales;
    float discount;
};

// Employee Structure
struct Employee {
    char name[100];
    float salary;
    int age;
    char username[100];
    char password[100];
    float bonus;
    int isAdmin;
};

// Customer Structure
struct Customer {
    char name[100];
    char username[100];
    char password[100];
};
```

### System Flow

```
┌─────────────┐
│   Start     │
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ Main Menu   │
└──────┬──────┘
       │
       ├──────► Login ────────► Role Selection ────► Role-Specific Menu
       │
       ├──────► Register ──────► Account Creation
       │
       ├──────► Operating Time ► Display Hours
       │
       └──────► Contact Us ────► Display Info
```

---

## 🔧 Configuration

### Customization Options

#### Maximum Capacity
```c
#define MAX 100  // Maximum products/employees/customers
```

#### Color Scheme (Windows)
```c
system("color 0A");  // Green text on black background
// Change to customize: system("color XY")
// X = Background, Y = Foreground
```

#### Shop Information
Modify the following functions to customize:
- `contactUs()` - Update contact details
- `openingTime()` - Modify operating hours

---

## 🐛 Known Issues

- 🔸 Password stored in plain text (educational purpose)
- 🔸 Data not persisted to file (in-memory only)
- 🔸 Limited to 100 items per category
- 🔸 Color command works only on Windows

### 🔜 Planned Fixes
- File-based data persistence
- Encrypted password storage
- Dynamic memory allocation
- Cross-platform color support

---

## 🗺️ Roadmap

### Version 2.0 (Planned)
- [ ] File-based data storage
- [ ] Password encryption
- [ ] Advanced search functionality
- [ ] Reporting module enhancement
- [ ] Graphical User Interface (GUI)

### Version 3.0 (Future)
- [ ] Multi-branch support
- [ ] Database integration
- [ ] Web-based interface
- [ ] Mobile application
- [ ] Real-time analytics

---

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

### How to Contribute

1. **Fork the Project**
   ```bash
   # Click the Fork button on GitHub
   ```

2. **Create your Feature Branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. **Commit your Changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```

4. **Push to the Branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

5. **Open a Pull Request**

### Contribution Guidelines

- Write clean, documented code
- Follow existing code style
- Test your changes thoroughly
- Update documentation as needed
- Be respectful and constructive

---

## 📜 License

This project is created for **educational purposes only**.

```
MIT License

Copyright (c) 2024 S. M. Mehedy Kawser

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
```

---

## 👨‍💻 Author

<div align="center">

### **S. M. Mehedy Kawser**

<img src="https://github.com/mehedyk.png" width="150" style="border-radius: 50%;" alt="Mehedy Kawser"/>

🎓 **BSc in Software Engineering**  
🏫 **Daffodil International University**

[![GitHub](https://img.shields.io/badge/GitHub-mehedyk-181717?style=for-the-badge&logo=github)](https://github.com/mehedyk)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-mehedyk-0077B5?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/mehedyk/)
[![Facebook](https://img.shields.io/badge/Facebook-mahdi.kawser-1877F2?style=for-the-badge&logo=facebook)](https://www.facebook.com/mahdi.kawser)

---

*"Simplicity is the ultimate sophistication."*  
— Leonardo da Vinci

</div>

### 🌟 About the Developer

I'm a passionate software engineering student with a keen interest in developing practical, user-friendly applications. This project started as a learning exercise when I was beginning my coding journey, and it has evolved into a comprehensive system that demonstrates the power of simple, well-structured code.

The main authenticity of this code lies in its simplicity. It was written when I was still learning the fundamentals, which forced me to improvise and create something truly beginner-friendly. Later, I refined and upgraded it to make it even more accessible to newcomers in programming.

---

## 🙏 Acknowledgments

Special thanks to:

- 🎓 **Daffodil International University** - For providing excellent education
- 👥 **Open Source Community** - For inspiration and support
- 📚 **C Programming Community** - For extensive resources
- 💡 **All Contributors** - For helping improve this project
- ☕ **Coffee** - For keeping me awake during late-night coding sessions

### Inspired By
- Traditional retail management systems
- The need for simple, educational software
- The beauty of command-line applications

---

## 📧 Contact

### Get in Touch

<div align="center">

📧 **Email**: [Contact via LinkedIn](https://www.linkedin.com/in/mehedyk/)

💬 **Discussions**: [GitHub Discussions](https://github.com/mehedyk/galacticos-super-shop/discussions)

🐛 **Bug Reports**: [GitHub Issues](https://github.com/mehedyk/galacticos-super-shop/issues)

🌟 **Feature Requests**: [GitHub Issues](https://github.com/mehedyk/galacticos-super-shop/issues/new)

</div>

---

## 📊 Project Stats

<div align="center">

![GitHub stars](https://img.shields.io/github/stars/mehedyk/galacticos-super-shop?style=social)
![GitHub forks](https://img.shields.io/github/forks/mehedyk/galacticos-super-shop?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/mehedyk/galacticos-super-shop?style=social)

### Support This Project

If you find this project helpful, please consider:
- ⭐ **Starring** the repository
- 🍴 **Forking** for your own experiments
- 📢 **Sharing** with others who might benefit
- 💬 **Providing feedback** and suggestions

</div>

---

## 🎉 Fun Facts

- 🚀 Written in pure C with no external dependencies
- 💚 Green-on-black theme inspired by classic terminals
- 🎯 Over 800 lines of carefully crafted code
- 📚 Perfect for learning C programming concepts
- 🌟 Handles up to 100 products, employees, and customers
- ⚡ Instant startup with pre-loaded demo data

---

<div align="center">

### 🌟 Star History

[![Star History Chart](https://api.star-history.com/svg?repos=mehedyk/galacticos-super-shop&type=Date)](https://star-history.com/#mehedyk/galacticos-super-shop&Date)

---

**Made by [MEHEDYK](https://github.com/mehedyk)**

### Show Your Support

If this project helped you, please consider giving it a ⭐ on GitHub!

---

*Last Updated: October 2025*

**Version 1.0.0** | [Changelog](CHANGELOG.md) | [Documentation](docs/) | [Issues](https://github.com/mehedyk/galacticos-super-shop/issues)

---

</div>

```ascii
   _____ _____    _____    _____ _______ _____ _____ ____   _____
  / ____|  __ \  / ____|  / ____|__   __|_   _/ ____/ __ \ / ____|
 | |  __| |__) || (___   | (___    | |    | || |   | |  | | (___  
 | | |_ |  _  /  \___ \   \___ \   | |    | || |   | |  | |\___ \ 
 | |__| | | \ \  ____) |  ____) |  | |   _| || |___| |__| |____) |
  \_____|_|  \_\|_____/  |_____/   |_|  |_____\_____\____/|_____/
                                                                   
              Super Shop Management System
```

</div>
