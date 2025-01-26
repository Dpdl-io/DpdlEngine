# File: ai/dpdlAISnakeGame.h
#
# Example: The code below uses the Dpdl language plug-in 'DpdlAINerd' to automatically generate a simple SNAKE Game console application
#			written in C
#
# author: A.Costa
# e-mail: ac@dpdl.io
#
#

println("testing the Dpdl language plugin 'DpdlAINerd' to automatically generate and execute code...")

>>ai
	>>c
	write a console program in C that implements the famous SNAKE game, with colorful graphics using ncurses colors
<<
int exit_code = dpdl_exit_code()

raise(exit_code, "Error in generating code from natural language description")

println("exit code: " + exit_code)

println("finished")
