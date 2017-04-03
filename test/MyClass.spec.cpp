#include "catch.hpp"
#include "../src/MyClass.hpp"

#define ACCESSOR(Name, Worker, Class, Member) \
    class Accessor_ ## Member : public Class { \
        public: using Class::Member; \
    }; \
    auto Name = static_cast<Accessor_ ## Member *>(&Worker);

TEST_CASE("MyClass Spec") {
    MyClass inst(42);

    SECTION("ctor sets size") {
        ACCESSOR(inst_access, inst, MyClass, m_size);
        REQUIRE(inst_access->m_size == 42);
    }
}
