# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to decode Expressions within statements of the Parser

class Expression:

    # The init function takes in the necessary parameters for the expression and ensures the expression
    # is written correctly
    def __init__(self, etype, tokens):
        self.etype = etype  # Given type of expression
        self.tokens = tokens  # Given line of tokens

        # Checks each given expression to ensure the expressions are correctly written
        if etype == "ASSIGNMENT":
            if tokens[0].id != 6001 or tokens[1].operator == "None" or tokens[1].id != 6010:
                raise Exception('Assignment Expression recognised, usage is incorrect.')
            if len(self.tokens) == 3 and tokens[2].id != 6001 and tokens[2].id != 6002:
                raise Exception('Assignment Expression recognised, usage is incorrect.')

        if etype == "ARITHMETIC":
            if (tokens[0].id != 6001 and tokens[0].id != 6002) or tokens[1].operator != "arithmetic":
                raise Exception('Arithmetic Expression recognised, usage is incorrect.')

        if etype == "BOOLEAN":
            if(tokens[0].id != 6001 and tokens[0].id != 6002) or tokens[1].operator != "relational":
                raise Exception('Boolean Expression recognised, usage is incorrect.')

        if etype == "ITER":
            if tokens[0].id != 6024 or tokens[1].id != 6002:
                raise Exception('Iteration Expression recognised, usage is incorrect.')

    # Prints the expression based on what type it is in the BNF format
    def print_encoded_expression(self):
        if self.etype == "ASSIGNMENT":
            print("<assignment_expression> -> " + self.write_tokens())
        if self.etype == "ARITHMETIC":
            print("<arithmetic_expression -> " + self.write_tokens())
        if self.etype == "BOOLEAN":
            print("<boolean_expression> -> " + self.write_tokens())
        if self.etype == "ITER":
            print("<" + self.tokens[0].type + " id:" + str(self.tokens[0].id) + "> <" + self.tokens[1].type + " id:" + str(self.tokens[1].id) + ">")
        for token in self.tokens:
            token.print_token()
        self.print_infix()

    # Writes the tokens in a BNF format, first by type then by ID
    def write_tokens(self):
        if len(self.tokens) != 3 and self.etype == "ASSIGNMENT":
            return "<" + self.tokens[0].type + " id:" + str(self.tokens[0].id) + "> <" + self.tokens[1].type + " id:" \
                   + str(self.tokens[1].id) + "> <arithmetic_expression>"
        else:
            return "<" + self.tokens[0].type + " id:" + str(self.tokens[0].id) + "> <" + self.tokens[1].type + " id:" \
                   + str(self.tokens[1].id) + "> <" + self.tokens[2].type + " id:" + str(self.tokens[2].id) + ">"

    # Prints tokens in an infix format
    def print_infix(self):
        if self.etype == "ITER" or (len(self.tokens) != 3 and self.etype == "ASSIGNMENT"):
            print(str(self.tokens[0].value) + " " + str(self.tokens[1].value))

        else:
            print(str(self.tokens[1].value) + " " + str(self.tokens[0].value) + " " + str(self.tokens[2].value))
