#include <iostream>

int doSomething(int* ptr){
    return *ptr;
}
std::string doSomethingToString(std::string* ptr){
    return *ptr;
}
template<class T>
class TestCastClass{
    void* value;
    T storage;
    public:
    TestCastClass(T value){
        this->storage = value;
        this->value = &storage;
    
    }
    T get_value(){
        std::cout<<this->storage<<"\n";
        //recover value from void pointer
        //this allows me to handle all my data using void pointers
        return *(T*)value;
    }
};
int main(){

    int x = 5;
    std::string s1 = "Hello World!";
    std::string s2 = doSomethingToString(&s1);
    s1 = "didnt work";
    std::cout<< s2<<"\n";
    int y = doSomething(&x);
    x = 6;
    std::cout<<y<<"\n";

    TestCastClass<int>* new_var = new TestCastClass<int>(2);

    int z = 5+new_var->get_value();
    std::cout<<z;
    return 1;
}