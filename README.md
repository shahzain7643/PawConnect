# PawConnect
PawConnect is a console-based C++ portal for managing pet adoptions, allowing staff to handle records and adopters to apply for pets.
## Architecture
### High-Level Diagram
![High-Level Diagram](High-Level%20Digram.png)
### Key Concepts and Objectives
- **Object-Oriented Design**  
  Implements inheritance, polymorphism, composition, aggregation, and association to represent real-world relationships between classes such as `Pet`, `Adopter`, `Staff`, and `Application`.

- **Role-Based Access**  
  - `Adopter`: Can browse pets and submit adoption applications.
  - `Staff`: Can add new pets, review applications, and update pet adoption statuses.

- **Data Persistence**  
  Uses binary file handling to save and restore pet and application data across sessions.

- **Pointer-Based Memory Management**  
  Dynamic memory is managed using pointers and raw arrays instead of STL containers, demonstrating low-level memory control.

- **Templates and Logging**  
  Utilizes template functions and classes for reusability, and includes a Logger class for tracking key system events.

- **Scalability**  
  The system structure allows for future enhancements such as GUI integration, networked database support, or role expansion.
