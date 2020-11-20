# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to decode Statements within blocks of the parser

from Parser.Decode_Expression import Expression


class Statement:
    line_index = 0

    # Begins with creating setting up local variables, then will break down the Expressions within each statement
    def __init__(self, line, etype):
        self.expressions = []
        self.print_tokens = []
        self.line = line
        self.etype = etype
        self.blocks = []

        if etype == "ASSIGNMENT":
            if len(line) == 3:
                self.expressions.append(Expression("ASSIGNMENT", line))
            else:
                self.expressions.append(Expression("ASSIGNMENT", line[0:2]))
                self.expressions.append(Expression("ARITHMETIC", line[2:5]))

        elif etype == "WHILE":
            self.expressions.append(Expression("BOOLEAN", line[1:4]))

        elif etype == "IF":
            self.expressions.append(Expression("BOOLEAN", line[1:4]))

        elif etype == "PRINT":
            if len(line) == 4:
                self.print_tokens.append(line[2])
            else:
                self.expressions.append(Expression("ARITHMETIC", line[2:5]))

        elif etype == "FOR":
            self.expressions.append(Expression("ASSIGNMENT", line[1:4]))
            self.expressions.append(Expression("ITER", line[4:6]))

    # Prints the Assignment along with its expression
    def print_encoded_statement(self):
        if self.etype == "ASSIGNMENT":
            if len(self.line) == 3:
                print("<assignment_statement> -> <assignment_expression>")
                self.expressions[0].print_encoded_expression()
            else:
                print("<assignment_statement> -> <assignment_expression> <arithmetic_expression>")
                for expression in self.expressions:
                    expression.print_encoded_expression()

        elif self.etype == "WHILE":
            print("<while_statement> -> while <boolean_expression> then <block>")
            self.expressions[0].print_encoded_expression()
            self.blocks[0].print_encoded_block()

        elif self.etype == "IF":
            print("<conditional_statement> -> if <boolean_expression> then <block> else <block>")
            self.expressions[0].print_encoded_expression()
            self.blocks[0].print_encoded_block()

        elif self.etype == "ELSE":
            self.blocks[0].print_encoded_block()

        elif self.etype == "PRINT":
            if len(self.print_tokens) != 0:
                print("<print_statement> -> print ( <" + self.print_tokens[0].type + " id:" + str(self.print_tokens[0].id) + "> )")
                self.print_tokens[0].print_token()
            else:
                print("<print_statement> -> print ( <arithmetic_expression> )")
                self.expressions[0].print_encoded_expression()

        elif self.etype == "FOR":
            print("<for_statement> -> for id = <iter> <block> end")
            for expression in self.expressions:
                expression.print_encoded_expression()




