# Kennesaw State University
# College of Computer and Software Engineering
# CS 4308, Concepts of Programming Languages, SN: 01
# Julia Parser In Python
# Leonard Hayes : lhayes32@students.kennesaw.edu
# 12/4/2019
# File Description: This file is used scan a given input
import re
from Scanner.Token import Token


class Scanner:
    # Identifiers
    identifiers = []

    # Collections
    tokenTree = []  # For Parser, holds token lines to interpret as a tree
    tokenCollection = []  # Collects tokens and lexemes to print for Scanner
    line_o_tokens = []  # Tracks lines of Tokens, places them in the token tree

    # Characters to watch for
    operators = ['=', '>=', '<=', '<', '>', '==', '!=', '+', '-', '*', '/', '%']
    letters = "[a-zA-z][a-zA-Z0-9_]*"
    number = "[0-9]+"
    parens = ['(', ')']

    # Index trackers
    global_index = 0
    local_index = 0
    line = 0

    # Previous input trackers
    current_line = ""
    previous_char = "NEWLINE"
    previous_string = ""

    # Dictionaries of Tokens
    token = {"identifier 6001": "[a-zA-z][a-zA-Z0-9_]*",
                  "literal_integer 6002": "[0-9]+",
                  "end_comment 6003": "[=][#]",
                  "le_operator 6004": "[>][=]",
                  "lt_operator 6005": "[>]",
                  "ge_operator 6006": "[=][<]",
                  "gt_operator 6007": "[<]",
                  "eq_operator 6008": "[=][=]",
                  "ne_operator 6009": "[!][=]",
                  "assignment_operator 6010": "[=]",
                  "unadd_operator 6011": "[+][a-zA-z][a-zA-Z0-9_]*",
                  "unsub_operator 6012": "[-][a-zA-z][a-zA-Z0-9_]*",

                  "add_operator 6013": "[+]",
                  "sub_operator 6014": "[-]",
                  "mul_operator 6015": "[^/|^*][*][^/|^*]",
                  "div_operator 6016": "[^/|^*][/][^/|^*]",
                  "pow_operator 6017": "[\\^]",
                  "literal_quote 6018": "[\"]",
                  "literal_comma 6019": "[,]",
                  "open_paren 6020": "[(]",
                  "close_paren 6021": "[)]",
                  "white_space 6022": "[\t]+|[\r]+|[\f]+|[ ]+",
                  "dot_pts 6023": "[.]",
                  "colon 6024": "[:]",
                  "literal_text 6025": "[^\"\\\\\\r\\n]*(?:\\\\.[^\"\\\\\\r\\n]*)*",

                  "begin_comment 6026": "[#][=][^\"\\\\\\r\\n]*(?:\\\\.[^\"\\\\\\r\\n]*)*",
                  "line_comment 6027": "[#][^\"\\\\\\r\\n]*(?:\\\\.[^\"\\\\\\r\\n]*)*",

                  "mod_operator 6028": "[%]",
                  "or_operator 6029": "[|][|]",
                  "and_operator 6030": "[&][&]",
                  "others 6031": ".+"}

    keywords = {"rsvp_whil 5001": "while",
                "rsvp_if 5002": "if",
                "rsvp_for 5003": "for",
                "rsvp_func 5004": "function",
                "rsvp_end 5005": "end",
                "rsvp_else 5006": "else",
                "rsvp_true 5007": "true",
                "rsvp_fals 5008": "false",
                "rsvp_prin 5009": "print"}

    # Main function, reads incoming symbols from a file and deciphers them
    def read_symbols(self, symbol):
        if symbol == " ":
            self.check_space()
            self.add_token()
            self.previous_char = "SPACE"
            self.local_index += 1
            self.global_index += 1

        elif symbol == "\n":
            self.check_newline()
            self.add_token()
            self.add_newline()
            self.previous_char = "NEWLINE"
            self.local_index = 0
            self.line += 1
            self.global_index += 1

        elif re.search(self.letters, symbol):
            self.current_line += symbol
            self.check_letter()
            self.previous_char = "LETTER"
            self.local_index += 1
            self.global_index += 1

        elif re.search(self.number, symbol):
            self.current_line += symbol
            self.check_num()
            self.previous_char = "NUMBER"
            self.local_index += 1
            self.global_index += 1

        elif self.is_operator(symbol):
            self.previous_char = "OPERATOR"
            self.local_index += 1
            self.global_index += 1

        elif symbol == "(" or symbol == ")":
            self.previous_char = "PAREN"
            self.local_index += 1
            self.global_index += 1

        elif symbol == ":":
            self.previous_char = "COLON"
            self.local_index += 1
            self.global_index += 1

        else:
            raise Exception('Invalid token at line {}, index {}'.format(str(self.line), str(self.local_index)))

    #Add Methods
    def add_token(self):
        if self.previous_char == "LETTER":
            if len(self.current_line) > 1:
                self.is_keyword()
                self.add_keyword()

            elif len(self.current_line) == 1:
                self.add_identifier()

        elif self.previous_char == "NUMBER":
            self.add_num()

        elif self.previous_char == "OPERATOR":
            self.add_operator()

        elif self.previous_char == "PAREN":
            self.add_paren()

        elif self.previous_char == "COLON":
            self.add_colon()

        self.current_line = ''

    def add_newline(self):
        self.previous_string = "NEWLINE"
        self.tokenTree.append(self.line_o_tokens)
        self.line_o_tokens = []
        self.current_line = ""

    def add_keyword(self):
        self.check_keyword()
        self.previous_string = "KEYWORD"
        for string in self.keywords:
            if re.search(self.keywords[string], self.current_line):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.keywords[string]))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.keywords[string]))
                return

    def add_operator(self):
        self.check_operator()
        self.previous_string = "OPERATOR"
        for string in self.token:
            if re.search(self.token[string], str(self.current_line)):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.current_line))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.current_line))
                return

    def add_paren(self):
        self.check_paren()
        for string in self.token:
            if re.search(self.token[string], self.current_line):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.current_line))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.current_line))
                return

    def add_colon(self):
        self.check_colon()
        self.previous_string = "COLON"
        for string in self.token:
            if re.search(self.token[string], self.current_line):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.current_line))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.current_line))
                return

    def add_num(self):
        self.check_num_string()
        self.previous_string = "NUMBER"
        for string in self.token:
            if re.search(self.token[string], str(self.current_line)):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.current_line))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.current_line))
                return

    def add_identifier(self):
        self.check_identifier()
        self.previous_string = "IDENTIFIER"
        for string in self.token:
            if re.search(self.token[string], str(self.current_line)):
                first_part = string.split()
                self.tokenCollection.append(Token(first_part[0], first_part[1], self.current_line))
                self.line_o_tokens.append(Token(first_part[0], first_part[1], self.current_line))
                if self.current_line not in self.identifiers:
                    self.identifiers.append(self.current_line)
                return

    # Confirmation Methods
    def is_keyword(self):
        for string in self.keywords:
            if str(self.current_line)in str(self.keywords[string]):
                return True
        raise Exception('Invalid token at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def is_paren(self, symbol):
        self.current_line += symbol
        for string in self.parens:
            if self.current_line in string:
                return True
        return False

    def is_operator(self, symbol):
        self.current_line += symbol
        for string in self.operators:
            if self.current_line in string:
                return True
        return False

    # Checking Methods (Strings)
    def check_operator(self):
        if self.previous_string == "OPERATOR":
            raise Exception('Invalid Operator at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_num_string(self):
        if self.previous_string == "NUMBER" or self.previous_string == "IDENTIFIER":
            raise Exception('Invalid Number at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_keyword(self):
        if self.previous_string == "KEYWORD" or self.previous_string == "NUMBER" or self.previous_string == "IDENTIFIER" \
                or self.previous_string == "OPERATOR":
            raise Exception('Invalid Operator at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_identifier(self):
        if self.previous_string == "IDENTIFIER" or self.previous_string == "NUMBER":
            raise Exception('Invalid Identifier at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_paren(self):
        if self.previous_string != "KEYWORD" and self.previous_string != "IDENTIFIER" and self.previous_string != "NUMBER":
            raise Exception('Invalid Parenthesis at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_colon(self):
        if self.previous_string != "NUMBER":
            raise Exception('Invalid Colon at line {}, index {}'.format(str(self.line), str(self.local_index)))

    # Checking Methods (Single characters)
    def check_letter(self):
        if self.previous_char == "LETTER":
            self.is_keyword()
        elif self.previous_char != "SPACE" and self.previous_char != "NEWLINE":
            raise Exception('Invalid token at line {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_num(self):
        if self.previous_char == "LETTER":
            raise Exception('Invalid token at line {}, index{}'.format(str(self.line), str(self.local_index)))

    def check_space(self):
        if self.previous_char == "NEWLINE":
            raise Exception('Unexpected space at start of line'.format(self.line))

        if self.previous_char == "SPACE":
            raise Exception('Double space at {}, index {}'.format(str(self.line), str(self.local_index)))

    def check_newline(self):
        if self.previous_char == "OPERATOR":
            raise Exception(
                'Unexpected end of line at line {}, index {}'.format(str(self.line), str(self.local_index)))
