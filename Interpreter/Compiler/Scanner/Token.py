# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to create tokens

class Token:
    def __init__(self, type, id, value):
        self.type = type
        self.id = int(id)
        self.value = value
        self.operator = "None"

        if value == '=':
            self.operator = "assignment"
        elif value == '+' or value == '-' or value == '/' or value == '*':
            self.operator = "arithmetic"
        elif 6009 >= self.id >= 6004:
            self.operator = "relational"

    def print_token(self):
        print("Token : <" + self.type + "  id:" + str(self.id) + "> Lexeme: " + str(self.value))
