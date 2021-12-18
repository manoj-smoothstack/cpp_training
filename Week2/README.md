# Week 2 Assignment: Implement a command line banking console for admin.

## Introduction

This is an extension to last week's project with the following additions:

* Add security.
* Add transactions.
* Add persistence and state. (Using google protobufs).
* Add for serialization/deserialization to a protobufs "database".
* Add error logging.

## Rules
* The code must be compilable with clang++ c++17 compiler on a Centos 8 or similar OS.
* Must have a way to build using make, cmake or something similar.
* The code needs to work in command line and self-contained and no external dependencies.
* Must include tests which should be runnable.

## Details
We will restrict the usage to "administrators" only for now.

The usage should be:

Usage: bankcli <file-name>

The <file-name> is the protobuf serializable. You will need to design the layout of the proto file.
Design a proto schema that works with your assignment submission.

Upon startup, the program will read the file specified by <file-name> and load all the account information. This
information is your database, and can be modified with your program. So if you add new accounts,
upon exiting the program, the proto file will reflect that change.

Use the google protobufs C++ library.

It should prompt for a username and password. The user and passwd must both be "demo".

user: <user>
password: <passwd>

You can embed the password in your ELF for now. This really should be encrypted with a solid
AES 256 bit encryption key, but for purposes of this class, we will relax that requirement!.

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
  - This should quit the program. This is a good time to save all the account information into the proto file.


## Checklist

As part of this project you may create the following C++ classes (modify them as per your design):

```
Account
Customer
ProtoReadWrite - Read/write the proto file (serialization)
Transaction
```
