Compares the compiler optimization on different type string declaration.
All major compilers (tried on g++, clang, msvc) optimizes out calls to strlen
for strings declared as:
const char *const text = "hello";
While even at O3 the call to strlen is not removed when string is declared at
char text[] = {'h', 'e', 'l', 'l', 'o', '\0'};

