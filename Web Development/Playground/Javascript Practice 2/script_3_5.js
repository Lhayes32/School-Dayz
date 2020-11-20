var a = 5;
var b = "5";
var theNumbersMatch;

//Others: >, <, >=, <=, !=, !== (strict)
if( a == b){
  theNumbersMatch = true;
} else {
  theNumbersMatch = false;
}

//True: 5 == "5"
console.log("The numbers match: " + theNumbersMatch);

if( a === b){
  theNumbersMatch = true;
} else {
  theNumbersMatch = false;
}

//False: Data types are different
console.log("The numbers match: " + theNumbersMatch);
