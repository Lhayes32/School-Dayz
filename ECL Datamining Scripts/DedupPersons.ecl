IMPORT $;

MyFile := $.Persons;


BRP := MyFile(BirthDate != ''): PERSIST('CLASS::LH::PERSIST::PREPROCESSED');
OUTPUT(BRP);