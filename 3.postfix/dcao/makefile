# This is a "makefile" for maintenance of Stack class code.
# 
# format:  lines come in pairs, dependency statement first,
# then action statement:
# 
# <target>:  <depend_1> ... <depend_n>
#	<action>
# 
# Here <target> depends on <depend_1> ... <depend_n>; if any of these
# files is newer than <target>, then <action> will be executed.
# Note that there's a TAB before <action> (which is a poor design).


# The command "make" by itself updates the first target, so the
# following standard line causes "make" to update our exectuble, i.
# Without this line, we'd need to run the comand "make i".
all: p

# If Stack.h or Stack.cxx is newer than Stack.o, then we need to
# compile Stack.cxx to produce Stack.o.
Stack.o: Stack.h Stack.cxx
	g++ -Wall -g -c Stack.cxx # The "-c" option says "make a ".o" file."

# If Stack.h or infix.cxx is newer than infix.o, then we need to
# compile infix.cxx to produce infix.o.
postfix.o: Stack.h postfix.cxx
	g++ -Wall -g -c postfix.cxx

# If Stack.o or infix.o is newer than i (the executable),
# then we need to compile (or link, really) Stack.o and
# infix.o to produce i.
p: Stack.o postfix.o
	g++ -Wall -g -o p Stack.o postfix.o

# This pair of lines causes "make clean" to remove all derived files.
clean:
	rm -f *.o i core
