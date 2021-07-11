IMPORT $;

//Part 2
MyFile := $.Persons;
SortedPersons := SORT(MyFile, LastName, FirstName);
DP := DEDUP(SortedPersons, LastName);
DDP:= DEDUP(DP, FirstName);
OUTPUT(SortedPersons);
OUTPUT(COUNT(DDP));