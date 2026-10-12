#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Question.h"

TEST_CASE("Insert and print a single person") {
    PList list([](const Person& a, const Person& b) { return a.name < b.name; });
    auto person = std::make_shared<Person>("John Doe", 30, "123 Elm Street");
    list.insert(person);
    CHECK_EQ((*list.begin())->name, "John Doe");
}

TEST_CASE("Prevent duplicate entries") {
    PList list([](const Person& a, const Person& b) { return a.name < b.name; });
    auto person = std::make_shared<Person>("John Doe", 30, "123 Elm Street");
    list.insert(person);
    list.insert(person); // Attempt to insert duplicate
    int count = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        count++;

        if (count > 2) // shouldn't happen
            break;
    }
    CHECK_EQ(count, 1);
}

TEST_CASE("Transform people in list") {
    PList list([](const Person& a, const Person& b) { return a.name < b.name; });
    auto person1 = std::make_shared<Person>("John Doe", 30, "123 Elm Street");
    auto person2 = std::make_shared<Person>("Jane Doe", 25, "456 Maple Avenue");
    list.insert(person1);
    list.insert(person2);
    list.transform([](const Person& p) { return Person(p.name, p.age + 10, p.address); });
    auto it = list.begin();
    // List is sorted by name: "Jane Doe" comes before "John Doe"
    CHECK_EQ((*it)->name, "Jane Doe");
    CHECK_EQ((*it)->age, 35);
    ++it;
    CHECK_EQ((*it)->name, "John Doe");
    CHECK_EQ((*it)->age, 40);
}

TEST_CASE("Iterating through list") {
    PList list([](const Person& a, const Person& b) { return a.name < b.name; });
    auto person1 = std::make_shared<Person>("John Doe", 30, "123 Elm Street");
    auto person2 = std::make_shared<Person>("Jane Doe", 25, "456 Maple Avenue");
    list.insert(person1);
    list.insert(person2);

    std::vector<std::string> names;
    for (auto it = list.begin(); it != list.end(); ++it) {
        names.push_back((*it)->name);
        if (names.size() > 3) // shouldn't happen
            break;
    }
    CHECK_EQ(names[0], "Jane Doe");
    CHECK_EQ(names[1], "John Doe");
}