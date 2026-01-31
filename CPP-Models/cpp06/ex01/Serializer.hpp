#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

struct Data {
    int id;
    char code;
};

class Serializer {
private:
    Serializer(); // Not initializable [cite: 152]
    Serializer(Serializer const &src);
    ~Serializer();
    Serializer &operator=(Serializer const &rhs);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif