#include <iostream>
#include <string>
using namespace std;

class animal
{
private:
    string name;
    int age;
    string sound;

public:
    animal(string name, int age, string sound);
    // Base class destructors should be virtual
    virtual ~animal();
    // Getters should be const as they don't modify member variables
    string getname() const;
    int getage() const;
    void bark() const;
};

class dog : public animal
{
public:
    dog(string name, int age, string);
    ~dog();
};

class cat : public animal
{
public:
    cat(string name, int age, string sound);
    ~cat();
};

int main()
{
    // Constructor for dog takes 2 arguments. Corrected variable name.
    dog *my_dog = new dog("dog", 5, "woof");
    cout << my_dog->getname() << endl;
    cout << my_dog->getage() << endl;
    my_dog->bark();
    delete my_dog;
    // Constructor for cat takes 2 arguments.
    cat my_cat("cat", 3, "meow");
    cout << my_cat.getname() << endl;
    cout << my_cat.getage() << endl;
    my_cat.bark();
    return 0;  
}

// Constructor definition was incorrect. It needs the class scope `animal::`
// and the signature must match the declaration.
animal::animal(string name, int age, string sound) : name(name), age(age), sound(sound)
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

void animal::bark() const
{
    cout << sound << endl;
}

// Missing constructor definition for dog. It must call the base class constructor.
dog::dog(string name, int age, string sound) : animal(name, age, sound)
{
    cout << "dog is created" << endl;
}

dog::~dog()
{
    cout << "dog is destroyed" << endl;
}

// Missing constructor definition for cat. It must call the base class constructor.
cat::cat(string name, int age, string sound) : animal(name, age, sound)
{
    cout << "cat is created" << endl;
}

cat::~cat()
{
    cout << "cat is destroyed" << endl;
}