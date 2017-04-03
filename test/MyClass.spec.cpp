#include "catch.hpp"
#include "../src/MyClass.hpp"

#define MAKE_ACCESSOR(Name, Inst, Class, Member) \
    struct Class ## _public_ ## Member : public Class { using Class::Member; }; \
    auto Name = static_cast<Class ## _public_ ## Member *>(Inst);

TEST_CASE("MyClass Spec") {
    MyClass inst(42);

    SECTION("ctor sets size") {
        MAKE_ACCESSOR(instPtr, &inst, MyClass, m_size);
        REQUIRE(instPtr->m_size == 42);
    }
}
