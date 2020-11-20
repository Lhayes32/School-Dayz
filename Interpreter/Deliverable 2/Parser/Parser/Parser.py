# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used to Parse the tokens given by the scanner

from Parser.Decoder import Decoder


class Parser:

    def __init__(self, collection):
        self.Collection = collection
        self.block = []

    def parse(self):
        if self.Collection[0][0].type != 'rsvp_func':
            raise Exception("Expected keyword \' Function \' at the beginning of the file")

        self.block = Decoder(self.Collection)
        self.block.decode_block(False)
        print("function " + self.Collection[0][1].value + "( ) <block> end")
        self.block.print_encoded_block()
        return self.block


