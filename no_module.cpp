#include <format>
#include <string>

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
