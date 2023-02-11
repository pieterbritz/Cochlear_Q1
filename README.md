# Cochlear_Q1
Cochlear Technical Challenge Question 1

Cochlear Rewards:
=================
(Please implement the solution to this question in C.)
Our company intends to start a new rewards program that gives our customers the chance to earn points on their purchases. 
Customers on the program are sorted into three tiers- Gold, Silver and Bronze, each with their own scheme for earning points. 
For this task you are to implement a module that, given the customer’s ID and the amount they have just spent, returns the total number of rewards points earned by the customer historically, including the points earned in the current transaction. The formula for calculating rewards points earned is presented below. 
All customers are identifiable by a unique 4 digit, integer ID. Assume all customers already exist in the system and are tied to one of the rewards tiers. 
For simplicity, you may assume that a primitive, statically allocated database is used to store the customer details, such as an array. Assume that there is a total of only 5 customers in the system but consider how your solution might be scaled in the future. 
Provide an interface to add a customer to the system. 

Rewards scheme 
Gold: 3 points earnt per dollar spent 
Silver: 2 points earnt per dollar spent 
Bronze: 1 point earnt per dollar spent 

The maximum amount a customer can spend in one transaction is $10,000. All rewards points and transaction amounts are integers.
