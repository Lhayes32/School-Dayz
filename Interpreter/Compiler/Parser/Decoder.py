# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to decode Blocks within the Parser

from Parser.Decode_Statement import Statement


class Decoder:

    current_line = 1

    def __init__(self, collection):
        self.collection = collection
        self.statements = []
        self.length = len(collection)
        self.index = 1

    def decode_block(self, boolean):
        while True:

            if self.length <= Decoder.current_line:
                break

            if self.collection[Decoder.current_line][0].id == 5005:
                Decoder.current_line += 1
                break

            if self.collection[Decoder.current_line][0].id == 5006 and boolean:
                break

            if 5009 >= self.collection[Decoder.current_line][0].id > 5000:

                if self.collection[Decoder.current_line][0].id == 5002:
                    statement = Statement(self.collection[Decoder.current_line], "IF")
                    self.statements.append(statement)
                    Decoder.current_line += 1
                    block = Decoder(self.collection)
                    block.decode_block(True)
                    statement.blocks.append(block)


                elif self.collection[Decoder.current_line][0].id == 5006:
                    statement = Statement(self.collection[Decoder.current_line], "ELSE")
                    self.statements.append(statement)
                    Decoder.current_line += 1
                    block = Decoder(self.collection)
                    block.decode_block(False)
                    statement.blocks.append(block)

                elif self.collection[Decoder.current_line][0].id == 5003:
                    statement = Statement(self.collection[Decoder.current_line], "FOR")
                    self.statements.append(statement)
                    Decoder.current_line += 1

                elif self.collection[Decoder.current_line][0].id == 5001:
                    statement = Statement(self.collection[Decoder.current_line], "WHILE")
                    self.statements.append(statement)
                    Decoder.current_line += 1
                    block = Decoder(self.collection)
                    block.decode_block(False)
                    statement.blocks.append(block)

                elif self.collection[Decoder.current_line][0].id == 5009:
                    statement = Statement(self.collection[Decoder.current_line], "PRINT")
                    self.statements.append(statement)
                    Decoder.current_line += 1

            elif self.collection[Decoder.current_line][0].id == 6001:
                statement = Statement(self.collection[Decoder.current_line], "ASSIGNMENT")
                self.statements.append(statement)
                Decoder.current_line += 1

    def print_encoded_block(self):
        print("<block> ->", end='')
        for statement in self.statements:
            print("<" + str(statement.etype).lower() + ">", end=' ')
        print("")
        for statement in self.statements:
            statement.print_encoded_statement()






