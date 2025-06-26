#include <iostream>

void printPassTypes(int pass_by_value, int& pass_by_reference, int* pass_by_pointer) {
    std::cout << "Running the function" << std::endl;
    // Pass by value - a new variable is created and the value of the argument is copied over
    // Pros: modifying the variable within the function doesn't modify the original variable
    // Cons: Generally slow and inefficient
    std::cout << "pass_by_value: " << pass_by_value << "\tAddress: " << &pass_by_value << std::endl;
    pass_by_value = 0;

    // Pass by reference - a new alias for the existing variable is created and passed to the function
    // Pros: Fast and efficient
    // Cons: If we'd like to perform some extra operations on the variable and store it in the same var,
    //       you have to declare a new variable and copy the value of the original one
    std::cout << "pass_by_reference: " << pass_by_reference << "\tAddress: " << &pass_by_reference << std::endl;
    pass_by_reference = 0;

    // Pass by pointer - we pass the address of the argument to the function
    // Pros: Similar to references, useful when wanting to do pointer manipulation (such as addressing array cells)
    // Cons: Dealing with pointers, means we have to dereference the value if we want to modify it
    std::cout << "pass_by_pointer: " << *pass_by_pointer << "\tAddress: " << pass_by_pointer << std::endl;
    //                                  ^                                    ^
    // v Notice the differences in accessing the values
    *pass_by_pointer = 0;

    std::cout << std::endl;
}

int main() {
    // ## Declaration
    int num = 5;     // This is a regular variable
    int& ref = num;  // ref stores a reference (alias) of num
    int* ptr = &num; // ptr stores a pointer (address) of num
    int** ptr_ptr = &ptr; // ptr_ptr stores a pointer (address) of ptr
    // You would use a pointer of a pointer for example to pass an array by pointer (arrays are stored as the pointer to the first element)

    // While we can declare variables and pointers and assign them later, references MUST be assigned at the moment of declaration

    // ## Declaring pointers and references
    // All of these declarations are synonymous
    int* ptr_1; // ptr_1 is a pointer to an int
    int *ptr_2; // dereferenced pointer ptr_2 is of type int
    int * ptr_3; // chaotic evil

    // It's a matter of preference; I prefer the 1st option but know when declaring multiple
    // pointers at once, the 2nd and 3rd option are the most consistent

    int* ptr_4, *ptr_5, * ptr_6;
    //          ^       ^
    // Note you HAVE TO repeat the star!

    // The above is exactly the same for pointers

    // ## Assigning pointers and references
    ptr = &num; // We use the `&` symbol to get the address of a num
    num = *ptr; // We use the `*` symbol to access the value pointed by a ptr

    // TODO: `->` and `.` for accessing elements of a struct or object

    // ## Passing arguments to functions
    int pass_by_value = 5, pass_by_reference = 10, pass_by_pointer = 15;
    std::cout << "Before the function ran:" << std::endl;
    std::cout << "pass_by_value: " << pass_by_value << "\tAddress: " << &pass_by_value << std::endl;
    std::cout << "pass_by_reference: " << pass_by_reference << "\tAddress: " << &pass_by_reference << std::endl;
    std::cout << "pass_by_pointer: " << pass_by_pointer << "\tAddress: " << &pass_by_pointer << std::endl;
    std::cout << std::endl;

    printPassTypes(pass_by_value, pass_by_reference, &pass_by_pointer); // Check the comments in the function body to learn more

    std::cout << "After the function ran: " << pass_by_value << " " << pass_by_reference << " " << pass_by_pointer << std::endl;
}
