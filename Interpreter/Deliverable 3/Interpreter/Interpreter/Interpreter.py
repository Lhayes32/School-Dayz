# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to interpret the code presented
from Scanner.Token import Token


class Interpreter:
    # Dictionary to keep track of identifiers
    dIdentifiers = {}

    # Interprets arithmetic expression
    @staticmethod
    def interpret_arithmetic(tokens):
        arithmetic = ''
        if tokens[0].id == 6001:
            arithmetic += str(Interpreter.dIdentifiers[tokens[0].value])
        else:
            arithmetic += tokens[0].value
        arithmetic += tokens[1].value
        if tokens[2].id == 6001:
            arithmetic += str(Interpreter.dIdentifiers[tokens[2].value])
        else:
            arithmetic += tokens[2].value
        number = str(eval(arithmetic))
        return Token("literal_integer", "6002", number)

    # Interpret assignment statements
    @staticmethod
    def interpret_assignment(tokens):
        if tokens[2].id == 6002:
            Interpreter.dIdentifiers[tokens[0].value] = tokens[2].value
        elif tokens[2].id == 6001:
            Interpreter.dIdentifiers[tokens[0].value] = Interpreter.dIdentifiers[tokens[2].value]

    # Print token values
    @staticmethod
    def print_token(token):
        if token.id == 6002:
            print(str(token.value))
        elif token.id == 6001:
            print(Interpreter.dIdentifiers[token.value])

    # Interpret boolean expression
    @staticmethod
    def interpret_boolean(tokens):
        boolean = ''
        if tokens[0].id == 6001:
            boolean += str(Interpreter.dIdentifiers[tokens[0].value])
        else:
            boolean += tokens[0].value
        boolean += tokens[1].value
        if tokens[2].id == 6001:
            boolean += str(Interpreter.dIdentifiers[tokens[2].value])
        else:
            boolean += tokens[2].value
        return eval(boolean)

    # Main interpretation method. Interprets statements gathered from the parser
    @staticmethod
    def interpret(statements):
        is_else = False
        for statement in statements:
            if statement.etype == "PRINT":
                if len(statement.expressions) == 0:
                    Interpreter.print_token(statement.line[2])
                else:
                    Interpreter.print_token(Interpreter.interpret_arithmetic(statement.expressions[0].tokens))
            elif statement.etype == "WHILE":
                while Interpreter.interpret_boolean(statement.expressions[0].tokens):
                    Interpreter.interpret(statement.blocks[0].statements)
            elif statement.etype == "IF":
                if Interpreter.interpret_boolean(statement.expressions[0].tokens):
                    Interpreter.interpret(statement.blocks[0].statements)
                else:
                    is_else = True
            elif statement.etype == "ELSE" and is_else:
                Interpreter.interpret(statement.blocks[0].statements)
                is_else = False
            elif statement.etype == "ASSIGNMENT":
                if len(statement.expressions) == 1:
                    Interpreter.interpret_assignment(statement.expressions[0].tokens)
                else:
                    line = [statement.line[0], statement.line[1], Interpreter.interpret_arithmetic(statement.line[2:5])]
                    Interpreter.interpret_assignment(line)












