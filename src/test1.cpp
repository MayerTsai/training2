#include <iostream>
#include <string>
using namespace std;

class animal
{
private:
    string name;
    int age;

public:
    animal(string name, int age);
    // Base class destructors should be virtual
    virtual ~animal();
    // Getters should be const as they don't modify member variables
    string getname() const;
    int getage() const;
    virtual void bark() const = 0;
};

class dog : public animal
{
public:
    dog(string name, int age);
    ~dog();
    void bark() const;
};

class cat : public animal

{
public:
    cat(string name, int age);
    ~cat();
    // A cat meows, not barks. Renaming for clarity.
    void bark() const;
};

int main()
{
    // Constructor for dog takes 2 arguments. Corrected variable name.
    dog my_dog("dog", 5);
    cout << my_dog.getname() << endl;
    cout << my_dog.getage() << endl;
    my_dog.bark();
    // Constructor for cat takes 2 arguments.
    cat my_cat("cat", 3);
    cout << my_cat.getname() << endl;
    cout << my_cat.getage() << endl;
    my_cat.bark();
    return 0;  
}

// Constructor definition needs the class scope `animal::` and the signature must match the declaration.
animal::animal(string name, int age) : name(name), age(age)
{
    cout << "animal is created" << endl;
}

animal::~animal()
{
    cout << "animal is destroyed" << endl;
}

string animal::getname() const
{
    return name;
}

int animal::getage() const
{
    return age;
}

// Missing constructor definition for dog. It must call the base class constructor.
dog::dog(string name, int age) : animal(name, age)
{
    cout << "dog is created" << endl;
}

dog::~dog()
{
    cout << "dog is destroyed" << endl;
}

void dog::bark() const
{
    cout << "woof" << endl;
}

// Missing constructor definition for cat. It must call the base class constructor.
cat::cat(string name, int age) : animal(name, age)
{
    cout << "cat is created" << endl;
}

cat::~cat()
{
    cout << "cat is destroyed" << endl;
}

void cat::bark() const
{
    cout << "meow" << endl;
}