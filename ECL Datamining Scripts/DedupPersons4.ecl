IMPORT $;

MyFile := $.Persons;

//Part 4
MP := MyFile(State[0] = 'M', Gender = 'M', (INTEGER)BirthDate >= 19800000);
OUTPUT(MP);