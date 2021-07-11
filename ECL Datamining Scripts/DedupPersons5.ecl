IMPORT $;

MyFile := $.Persons;

//
rec := RECORD
MyFile.Gender;
MyFile.State;
END;

CT := TABLE(MyFile, rec, Gender, State);
OUTPUT(CT);