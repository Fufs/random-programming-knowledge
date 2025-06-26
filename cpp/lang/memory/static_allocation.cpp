#include <iostream>

int this_var_will_be_zero;     // All global vars are initialized to 0;
int this_var_will_be_five = 5; // You can assign a value at the moment of initialization

void print_local_var() {
    // std::cout << "this_var_will_be_also_five: " << this_var_will_be_also_five << std::endl; // this will cause a compilation error, as the function does not have access to the local scope of main()
    int this_var_will_be_also_also_five = 5;
    std::cout << "this_var_will_be_also_also_five: " << this_var_will_be_also_also_five << std::endl; // now it's fine
}

int main() {
    std::cout << "this_var_will_be_zero: " << this_var_will_be_zero << std::endl;
    std::cout << "this_var_will_be_five: " << this_var_will_be_five << std::endl;

    int this_var_will_be_also_five = 5; // Vars declared in a local scope, will only be available in this scope, and "sub" local scopes
    int this_var_will_be_garbage;       // Vars declared in a local scope, without an assignment, will contain garbage (the previous contents of memory at that address)

    std::cout << "this_var_will_be_also_five: " << this_var_will_be_also_five << std::endl;
    std::cout << "this_var_will_be_garbage: " << this_var_will_be_garbage << std::endl;
    print_local_var();

    {
        // You can create a local scope by simply putting your code in curly brackets.
        // All variables declared in a local scope will be deleted as soon as the execution leaves the scope
        int this_var_will_be_two = 2;

        std::cout << "this_var_will_be_two: " << this_var_will_be_two << std::endl;
    }

    // std::cout << "this_var_will_be_two: " << this_var_will_be_two << std::endl; // this will cause a compilation error, as this will be two was destroyed


    // All the variables here are statically allocated and stored in a stack. Deallocation of memory and deletion of variables happens automatically
    // after the execution leaves the scope. There's no way to do it manually.
}
