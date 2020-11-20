# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: Main File

from Scanner.Scanner import Scanner
from Parser.Parser import Parser
from Interpreter.Interpreter import Interpreter


testcode = open("test.txt", "r")
data = testcode.read()
scan = Scanner()
for symbol in data:
    Scanner.read_symbols(scan, symbol)

print("Scanner")
for token in scan.tokenCollection:
    token.print_token()

print("-----------------------------------")
print("Parser")
parser = Parser(scan.tokenTree)
parse_decoded = parser.parse()

print(parse_decoded)

print("-----------------------------------")
print("Interpreter Output")
for identifiers in scan.identifiers:
    Interpreter.dIdentifiers.update({identifiers: 0})

Interpreter.interpret(parse_decoded.statements)
