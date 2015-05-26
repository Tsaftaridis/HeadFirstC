// This is a File with reference material to the basic concepts of presented in the first chapters of most books.
// This is tailored for personal use and convenience. 
// ! THIS WILL OBVIOUSLY NOT COMPILE AND/OR RUN !

CONTINUE AT PAGE 60 OF HFC...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// LOOPS

// switch usage. Can use fall through logic (e.g. 2-3). CRITICAL: Break statements. Also 
// makes code easier to understand.

switch (val)
{
	case 1:
		win();
		break;
	case 2:
		lose();
	case 3:
		game_over();
		break;
	default
		do_nothing;
}

do
{
	//buy lottery ticket
}while(not_have_won);

// Break: Get out of the loop immediately, ignoring any code left.
// SOS: CANNOT {REPLACE WHILE with IF} -->> BUGS!!!
while(feeling_hungry)
{
	eat_cake;
	
	if (feeling_queasy)
		break;
		
	drink_coffe;	
}

// Continue: Skips the rest of the loop's code, for as long as a condition is (not) met.
while(feeling_hungry)
{
	// Go back to "while"
	if(not_lunchtime_yet)
		continue;
		
	eat_cake();
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// STRINGS
char name[size];
// Variable size of 
void fortune_cookie(char msg[])
// Creates 
char quote[] = "Cookies make you fat.";
// Differences between array variables and pointers.
char s[] = "How big is it?"
char* t = s;
sizeof(s) == 15; // Returns true
sizeof(t) == 4; // Returns true. Sometimes returns true for 8, depending on the system.
// T is a separate variable than the string it points to, so it has a different address.
// S is not a separate variable, but an array, so it has the same address as the first 
// character of the array
// VALID:
&s == s;
&t != t;
// So, you cannot do the following without a compiler error. INVALID:
s = t;
// SOS: the t pointer doesn't know how big the s array is (pointer decay).
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// STANDARD OUTPUT/INPUT
puts("Your Message Here");
scanf("%format", variable);
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// POINTERS

printf("x lives in: %p", &x);

// When used for a declaration, star indicates a pointer.
// i.e. make a pointer and point it to the address &x;
int* address_of_x = &x;

// When not used in declaration, star indicates the value pointed to by the pointer.
// i.e. Get the value at address_of_x
int value stored = *address_of_x;

// Converting pointers to numbers:
a = (long)p // Outside of the declaration you do not use a star to refer to a pointer. 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// FORMATS ( SYNTAX NONSENSICAL )
p -> hexadecimal;
%d -> decimal;
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DATA INPUT/OUTPUT
// STANDARD OUTPUT/INPUT
puts("Your Message Here");
scanf("%format", variable);
// Basic scanf

// "name" is an array or a pointer. "scanf" just updates the contents of name
char name[40];
char surname[80];
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
// Not specifying the number of characters scanned may cause crashes if input > expected.
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
scanf("%39s %79s", name, surname);
// That is why when not using an array, you need to pass scanf the address of the variable
int age;
scanf("%i", &age);

// Basic fgets

char food[5];
char* drink;
// Takes: pointer to buffer/string, the maximum size '\0' included, data stream
// SOS: if the pointer is not an array indicator, give it an EXPLICIT SIZE!!!
fgets(food, sizeof(food), stdin);
fgets(drink, 5, stdin);
// INVALID:
fgets(drink, sizeof(drink), stdin);
// 'Cause sizeof(drink) == 8 or 4 (see P-O-I-N-T-E-R-S)

//-------------------------------------------------fgets vs scanf
? LIMITS THE NUMBER OF INPUTED CHARS(MANDATORY):	YES		NO
? MORE THAN ONE FIELD:								NO		YES
? SPACES IN STRING:									YES		NO
// SCANF CANNOT READ SPACES IN A %S INPUT BASIS!!!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// TRIVIA
// sizeof is not a function. It is a set of commands run by the compiler. 
// That means the performance of the code is not affected by the number of sizeofs you use.
sizeof(var);
