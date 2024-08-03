#include "Serializer.hpp"

int main(void)
{
    Data d;
    Data *d_ptr = &d;
    uintptr_t raw;
    Data *d_return;

    d.c = 'M';
    d.i = 42;

    raw = Serializer::serialize(d_ptr);
    d_return = Serializer::deserialize(raw);

    std::cout << "Original Address: " << d_ptr << std::endl;
    std::cout << "d_ptr: c = " << d_ptr->c << ", i = " << d_ptr->i << "." << std::endl;

    std::cout << "Deserialized Address: " << d_return << std::endl;
    std::cout << "d_return: c = " << d_return->c << ", i = " << d_return->i << "." << std::endl;

    std::cout << "Result: " << (d_ptr == d_return) << std::endl;

    return 0;
}