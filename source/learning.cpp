#include "learning.hpp"

//-------------------//
//  String Learning  //
//-------------------//

void StringLearning::string_init ()
{
    string s1;            // default initialization; s1 is the empty string
    string s2 = s1;       // s2 is a copy of s1 
    string s3 = "hiya";   // s3 is a copy of the string literal
    string s4(10, 'c');   // s4 is cccccccccc

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

void StringLearning::string_operater_write_read ()
{
    string word;
    while (cin >> word)       // read until end-of-file
        cout << word << endl; // write each word followed by a new line
    cout << "EOF detectded" << endl;
}

void StringLearning::string_add ()
{
    string s1  = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;    // s3 is hello, world\n
    s1 += s2;               // equivalent to s1 = s1 + s2
}

void StringLearning::string_iterate ()
{
    string str("some string");

    // print the characters in str one character to a line
    for (auto c : str)      // for every char in str
        cout << c << endl;  // print the current character followed by a newline

    // convert str to uppercase
    for (auto &c : str)     // for every char in str (note: c is a reference)
        c = toupper(c);     // c is a reference, so the assignment changes the char in s
    cout << str << endl;
}

void StringLearning::string_str_to_digit ()
{
    const string hexdigits = "0123456789ABCDEF"; // possible hex digits
    cout << "Enter a series of numbers between 0 and 15"
        << " separated by spaces. Hit ENTER when finished: "
        << endl;
    string result;        // will hold the resulting hexify'd string
    string::size_type n;  // hold numbers from the input
    while (cin >> n)      // If cin could not transfer to size_type, loop would be break too.
        if (n < hexdigits.size())    // ignore invalid input
            result += hexdigits[n];  // fetch the indicated hex digit
    cout << "Your hex number is: " << result << endl;
}

//-------------------//
//  Vector Learning  //
//-------------------//

void VectorLearning::vector_init ()
{
    vector<int> ivec;             // initially empty
    vector<int> ivec2(ivec);      // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec;     // copy elements of ivec into ivec3
    // vector<string> svec(ivec2);   // error: svec holds strings, not ints
    
    vector<string> articles = {"a", "an", "the"};  // list initialization

    vector<int> _ivec(10);             // ten elements, each initialized to 0
    vector<int> _ivec2(10, -1);        // ten int elements, each initialized to -1
    vector<string> _svec(10);          // ten elements, each an empty string
    vector<string> _svec2(10, "hi!");  // ten strings; each element is "hi!"
}

void VectorLearning::vector_add ()
{
    // read words from the standard input and store them as elements in a vector
    string word;
    vector<string> text;       // empty vector
    while (cin >> word) {
        text.push_back(word);  // append word to text
    }
}

//------------------------//
//  Convertions Learning  //
//------------------------//

void ConversionsLearning::implicit_convertions ()
{
// There are a lot of arithmetic convertions that I ignore.

   //  Array to Pointer Conversions
// int ia[10];   // array of ten ints
// int* ip = ia; // convert ia to a pointer to the first element

   // Conversions to bool
// char *cp = get_string();
// if (cp) /* ... */      // true if the pointer cp is not zero
// while (*cp) /* ...  */ // true if *cp is not the null character

   // Conversions Defined by Class Types
// string s, t = "a value";  // character string literal converted to type string
// while (cin >> s)          // while condition converts cin to bool
}

void ConversionsLearning::explicit_convertions ()
{
    // cast-name<type>(expression);
    // "type" is the target type of the conversion.
    // "expression" is the value to be cast.
    // "cast-name" determines what kind of conversion is performed.

    // address of any nonconst object can be stored in a void*
    // void* p = &d;
    // converts void* back to the original pointer type
    // double *dp = static_cast<double*>(p);
}