<h2><b>Problem 1:</b><br/></h2>
 Make a structure -rational number ,that has the following methods: reads information about a rational number, prints information,  - , * , / ,== and a boolean function isLessThan(const Rat&, const Rat&).
 
<h2><b>Problem 2:</b><br/></h2>
Make a structure library a combination of structure reader and book.It must have the following functions:add(book ,reader),remove book , rent a book ,find a rented book by given reader,by given name of a book ,return if it has a free copy, sort books by name.

<h2><b>Problem 3:</b><br/></h2>
Define a class,describing polynomial with coef of integers. Define proper constructors and functions for printing polynomial , calculating polynomial with given x:    <type> evaluate (double x) const , changing certain coef void setCoef(int degree, <type> newCoef) and returning certain coef <type> getCoef(int degree) const.

<h2><b>Problem 4:</b><br/></h2>
Define a class,describing playing cards using enum.Define proper functions.Then define a class :deck of cards ,representing an array of cards ,index top and proper functions. Use the algorithm of Fisher-Yates to shuffle the cards.

<h2><b>Problem 5:</b><br/></h2>
Define a class Vehicle,then make class Car and Bycicle ,which inherit the first class. Make proper methods and functions.

<h2><b>Problem 6:</b><br/></h2>
The Bulgarian Train System(in Bulgaria - BDZ) has a long history and tradition. They want to make a better ticket system. They have told that,there are trains that travel only from point A to point B ,because they are very old and can't stop everywhere. What is more,they have a limited amount of tickets with no certain order.(the seat number are worn out)
Make a system, which allows to sell ticket for a certain train. Before making the deal ,you have to check if there are free tickets and if the train stops in the places A and B. There are 3 kind of tickets-Normal,Student(-50%) and Group ticket(-30% ,for more than 4 passengers). 
BDZ must always know how much money was earned from ticket selling.

<h2><b>Problem 7:</b><br/></h2>
Make a system for a laboratory,which makes tests.Every test has a name,price and time.Test can be individual, or several tests.Individual tests have also an minimal and max points for normal results.Package tests,including several tests are represented as an array of tests and have a 10% discount.The time of the package tests is the max time of a  test in the array.
In this laboratory the tests are made in the order they have been added. (a queue of tests).Make proper functions for adding,removing ,calculating the sum of money of all tests and a function returning the test with the minimal time.
