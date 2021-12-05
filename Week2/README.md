# Week 2 Assignment: Implement a command line banking console for admin.

## Introduction

This is an extension to last week's project with the following additions:

* Support transactions.
* Support persistence and state. (Using JSON file).
* Use and/or write a JSON DOM parser.
* Complete OOP model and design.
* Complete error logging.
* Use dynamic memory and references.

## Constraints

# Basic C++ Compatibility
* Write all your code in C/C++ syntax.
* The code must be compilable with clang++ c++17 compiler on a Centos 8 or similar OS.
* The code must be buildable, and use a Makefile syntax.
* The Makefile should be called Makefile, and simply need to type "make" to build it with no options.
* The executable must run successfully on a Centos 8 or similar OS.
* Check in your code into your github account for this week.
* Make sure your code works in command line and not dependent on an IDE to run.
* There should be no dependencies of your code on any library other than standard C++ library.
* Include a JSON file with accounts and transactions populated by your program.

# Documentation and Validation
* You need to provide a short summary inside the code, and add helpful comments.
* Any performance inefficiency considerations need to be documented.
* Any caveats, limitations need to be documented in the code.
* Perform error checking for all user input, using separate functions for each.

# Use of C++ features
* Declare constructors and destructors where necessary.
* Define all classes with appropriate .h header files.
* Use const where necessary and non-judiciously.
* Use array/vector where necessary.
* Use loops (for and while), if else, switch etc where necessary.
* Use cin and cout for all your input and output streams. Make appropriate use of manipulators.
* Demonstrate validation of fields that are strings, and numbers.
* Demonstrate where you prefer references over pointers and vice versa.

# Performance and Error Considerations
* Your program will be evaluated for memory leaks.
* Use dynamic memory whereever possible, and justify reasons why you are not using dynamic memory in other places.
* Perform appropriate error checking with asserts. Your code must be bullet proof. (Never say die!)
* All errors needs to be appended to a log file "bank.log" in the same directory, which includes the date, userid, action, error, error code.


## Details
We will restrict the usage to "administrators" only for now.

The usage should be:

Usage: bankcli <file-name>

The <file-name> is a JSON file. You will need to design the layout of this file, but an example
is given in bank.json. The schema here may not be complete. You can design a JSON schema that works
with your assignment submission.

Upon startup, the program will parse the <file-name> and load all the account information. This
information is your database, and can be modified with your program. So if you add new accounts,
upon exiting the program, the bank.json will reflect that change.

You can use the rapidjson C++ library, if you like. And you should use the DOM (Document Object Model)
parser. But if you really want to push the limits, you can write your 
own JSON parser! Extra credit will be given to those who can write their own JSON parser, even if it
is substantially simpler and only works for this JSON file.

It should prompt for a username and password. The user and passwd must both be "demo".

user: <user>
password: <passwd>

You can embed the password in your a.out for now. (This really should be encrypted with a solid
AES 256 bit encryption key, but for purposes of this class, we will relax that requirement!).

If authentication succeeds, you will show the console prompt, or else you will display
message "Incorrect user" and ask for the user again in a while loop. Here is the console prompt:

home > 

At the console prompt you should be able to enter the following commands:

1. "show accounts"
2. "display account"
3. "search name"
4. "new account"
5. "close account"
4. "quit"


## Commands

### "show accounts"

   - this should display all accounts (one per line):

     Customer Name, Account, Date Opened

### "display account"

   - this should display a prompt for account number

     account > 

     The user enters the account number, and if it is invalid, it shows an error "invalid account"
     and comes back and shows the home prompt.
     If the account is valid, it should show the following:
     Customer Name:
     SSN: With only last 4 digits displayed
     Date Opened:
     Account:

     Add Transaction >
     Home >

     At this point you have the ability to add a new transaction or go back to Home screen.

### "add transaction"

   - this should take the following input:

     Amount:
     Debit/Credit: <debit/credit>:
     
     If the debit is greater than the balance, it will show an error message "Insufficient balance".
     and bring you back to "display account". 

     If the debit is smaller than the balance, it will add the transaction and update the balance.

### "search name"

   - this should display a prompt for account name. It should search by first name and last
     name. Show the exact matches on top, and the approximate matches later.

     name > 
     The user enters the exact customer name, and it shows all matches as 
       1) Bob Parsons
       2) Bob Parson
       3) Bobby Parsons
       4) Home
     Select number > 3

     If the user enters 3, it shows the account. If the user enters any invalid number,
     it shows an error "Invalid number" and displays the "enter name" prompt.
     The user can enter Home and go back to Home.

     The account screen for a customer name should look like shown in "display account".

     You do not need to show transactions (at least not yet).

### "new account"

   - This will ask admin for following information.

     Customer Name > (characters and spaces only)
     SSN > (9 digits)

     After these are input, a new account will be created if these are unique, otherwise it will
     give an error message "Account exists" and display the home prompt.

     The new account created will have an account number.
     Each customer can have only one account for now.

### "close account"
  - This will ask for the account number:

     account > (account)

    Do process error message and ask for confirmation to close account with a yes or no.

### "quit"
  - This should quit the program. This is a good time to save all the account information into bank.json.


## Checklist

As part of this project you will create the following C++ classes:

Account
Customer
JsonLoader - parse the JSON file
AccountData - after parsing, all the data is loaded into an AccountData class
