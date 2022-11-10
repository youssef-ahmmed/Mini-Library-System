# Mini-Library-System
Console Application Project

## Background
- Many libraries have a library system.
  - Helps adding books and searching for them.
  - Maintains information about the borrowed books.
- This is a simple version of this classical systems.
- The main user for the system is an admin.
  - Who might add a book, user or perform some relevant operation.
  - There is no e login/logout functionalities in this console system.
- The system starts with a menu.
  - It shows all possible choices.
  - The admin selects a choice and some operation is performed.
  
## The menu
![image](https://user-images.githubusercontent.com/115221628/201103117-a10f1397-7f4c-4985-8366-691655f151df.png)
 
 
## Books Operation
**1. Adding a book**
- The admin needs to be able to add books.
- Each book has the following information.
  - id - name - quantity
  
**2. Searching for a book**
- We will search the system using book name.
- Instead of the complete book name, we will allow a prefix.
  - Prefix: The first letters of a word.

**3. Listing books**
- Another typical operations is to just list all books in the system.
  - But we can order data in several ways!
- We will allow sorted either based on IDs or Names.
- Assume entered books were.
  - ID: 1111, Name: Math1
  - ID: 5041, Name: ArabicLiterature
  - ID: 1011, Name: Math2
- Sorting by name ⇒ ArabicLiterature, Math1, Math2.
- Sorting by ID ⇒ Math2, Math1, ArabicLiterature.

**4. Listing users borrowed a book**
- Given that several users may borrow a book, the admins may want to know who borrowed what. We have several copies per book.
- Input: *Book Name*
  - E.g. Math1
- Output: list of the user names who borrowed the book
  - E.g. Mostafa, John, Mark, Ali

## User Operations
**1. Add a user**
- Each user has only an Id and Name.
- We only request 2 operations.
 - Borrowing a book.
 - Returning a book.

**2. Borrow a book**
- Borrowing books is a repetitive scenario in libraries.
- Each book already have a specific number of copies (the quantity).
- To borrow a book, this quantity must be > 0
  - Otherwise, this book can’t be borrowed.
- After borrowing, the quantity must be decreased.
- The admin enters the user name and the book name.
  - If there is enough quantity of the book, the system does the following:
    - Mark that this user borrowed a copy.
    - Decrease the quantity with 1
  - If there is no available copies, the system notifies the admin.
  
**3. Return a book**
- Same logic, but this time the system do the reverse:
   - Mark that the user returned a copy.
   - Increment the current quantity.



  
 



  
  
