#include <format>
#include <string>
#include <type_traits>

class refactor_me
{
    std::string member1{};

public:
    refactor_me(std::string_view sv): member1{sv} {}
    auto get_text()
    {
        return member1;
    }
};

auto bar() -> std::string
{
    using namespace std::literals;
    auto r = refactor_me{"abc"sv};
    return std::format("Hello {}", r.get_text());
}

template <typename T>
concept Foo = requires(T t)
{
    { t.method1() } -> std::same_as<std::string>;
};


auto test_foo(Foo auto arg1) -> std::string {
    return arg1.method1();
}
