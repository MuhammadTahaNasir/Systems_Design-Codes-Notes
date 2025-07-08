# 🛒 Bazaar - Scalable Online Marketplace System (LLD  Design)

**Bazaar** is a modular, extensible low-level design (LLD) of an online marketplace application inspired by platforms like **Daraz**. Tailored for LLD interviews and system design evaluations, it showcases clean architecture, UML diagrams, and C++ implementation which is designed to be scalable, user-friendly, and relevant for real-world use cases in regions like Pakistan.

---

## 📌 Table of Contents
- [Project Goal](#project-goal)
- [Step 1: Requirement Gathering](#step-1-requirement-gathering)
  - [Functional Requirements](#functional-requirements)
  - [Non-Functional Requirements](#non-functional-requirements)
  - [Clarifications with Interviewer](#clarifications-with-interviewer)
- [Step 2: Happy Flow Discussion](#step-2-happy-flow-discussion)
- [UML Diagrams](#uml-diagrams)
- [Implementation Details](#implementation-details)
- [Tech Stack](#tech-stack)
- [How to Run](#how-to-run)
- [Future Extensions](#future-extensions)

---

## 🎯 Project Goal
To design a clean, object-oriented architecture for an e-commerce platform that allows users to:
- Search and purchase products (e.g., *Embroidered Shalwar Kameez*, *Samsung Galaxy A14*)
- Select delivery/pickup options
- Make local payments (e.g., *JazzCash*, *Credit Card*)
- Receive order confirmations

---

## ✅ Step 1: Requirement Gathering

### 🔧 Functional Requirements
- **User Actions**
  - Search products by category/location (e.g., Karachi, Lahore)
  - Browse seller listings and add products to cart
  - Place orders (delivery or pickup)
  - Pay via local methods (JazzCash, Credit Card, EasyPaisa)
  - Receive notifications via SMS/WhatsApp

- **Core Entities**
  - `User`: Identified with CNIC-based ID
  - `Seller`: Represents vendors across markets
  - `Product`: Item listings (name, price, code)
  - `Cart`: Holds products from a single seller
  - `Order`: Captures user, seller, product, and payment details
  - `Payment`: Strategy-based payment support
  - `Notification`: Sends order confirmations

- **Persistence**
  - Order data is saved to file (extensible to DB like MongoDB)

### ⚙️ Non-Functional Requirements
- **Scalability**: Handles users/sellers in cities like Lahore, Karachi, Peshawar
- **Loose Coupling**: Decoupled components using strategy and factory patterns
- **Extensibility**: Plug-in new payment methods or product types
- **Maintainability**: Clean C++ code, follows SOLID principles
- **Performance**: Optimized for fast search and quick checkout

### 📋 Clarifications with Interviewer
- **Focus Scope**: Prioritize user flow, not seller product management
- **Payment**: Assume 3rd-party integrations (e.g., JazzCash API)
- **Notification**: External services (e.g., Twilio, WhatsApp)
- **Scheduled Orders**: Support both immediate and scheduled deliveries

---

## 😊 Step 2: Happy Flow Discussion

1. **User Searches Products**
   - By category or location (e.g., "Electronics", "Lahore")
2. **User Selects Seller/Product**
   - Browses listings, adds item to cart
3. **User Places Order**
   - Chooses pickup/delivery, selects payment method
4. **Order Confirmation**
   - System sends notification and clears the cart

---

## 📐 UML Diagrams

The following diagrams were created to visualize system design:

- ✅ **Class Diagram**: Shows core entities and their relationships  
- ✅ **Sequence Diagram**: Captures the "place order" flow  
- ✅ **Design Patterns**: 
  - Strategy (Payment)
  - Factory (Order)
  - Composition/Aggregation/Inheritance

You can view them via `.puml` files or PlantUML-rendered images in the `uml/` folder.

---

## ⚙️ Implementation Details

The code is written in **modular C++** and follows OOP principles:
- Interfaces for strategy and factory patterns
- Clear separation of concerns (Single Responsibility)
- Codebase ready for integration with file I/O or REST APIs

---

## 🛠️ Tech Stack

| Layer        | Technology      |
|--------------|-----------------|
| Language     | C++             |
| Diagrams     | PlantUML        |
| Storage      | File (optional: MongoDB) |
| Notification | SMS/WhatsApp Integration (future) |

---

## ▶️ How to Run

1. Clone this repo:
   ```bash
   git clone https://github.com/your-username/bazaar-ll-design.git
   cd bazaar-ll-design
    ```

2. Compile the project:
    ```bash
    g++ -std=c++17 src/*.cpp -o bazaar
    ./bazaar
    ```
3. For UML:

Open `.puml` files in PlantText or VS Code with the PlantUML extension.

---

## 🚀 Future Extensions

- ✅ Add seller product management flow
- ✅ Integrate database (e.g., MongoDB or SQLite)
- ✅ Add REST API support using FastAPI or gRPC (for microservices)
- ✅ Real payment gateway integration (e.g., JazzCash SDK)
- ✅ Admin dashboards and analytic

---