// This is our second group work exercise, Group2.
// 
// postfix.cxx evaluates a postfix expression consisting of digits and
// the operators + and *.
// 
// Please turn in four files:
// - postfix.cxx
// - Stack.h
// - Stack.cxx
// - makefile
// 
// Here is the algorithm:
// - While there is more input,
//    - read a character from input
//    - if a digit, push its value onto a stack of integer operands
//    - if an operator, pop the stack twice, perform the operation,
//      and push the result on the stack
// - Pop the stack to get the result
//
// Notes:
// - To get from a character like '3' to the integer 3, subtract the
//   character '0'. For example, 
//     char c = '3';     // c's value is the character '3'
//     int  i = c - '0'; // i's value is the integer 3
//   (This works because '3' is encoded as 51 and '0' is encoded as 48.)
// - You will need a stack of integer operands. Convert my stack to
//   use integers, not characters.
// - You should revise my makefile to produce an executable "p".
// - One fun way to run p is to run "i | p", using the Linux pipe
//   operator, "|". The "i | p" command says "use the output of i as
//   the input of p." You can then provide infix input to "i | p". The
//   infix program will convert it to postfix, and the postfix program
//   will evaluate the postfix.
// 
// Here are two extra challenges:
// - Also implement the operators - and /.
// - Process not only one-digit numbers, but also numbers of several
//   digits, like 152. (Still read numbers one character at a time.)
