#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <iterator>

class Person {
public:
    std::string name;
    int age;
    std::string address;

    Person(const std::string& name, int age, const std::string& address);
    void print() const;
    bool operator==(const Person& other) const;
};

class PList {
    using TransformFunc = std::function<Person(const Person&)>;
    using Comparator = std::function<bool(const Person&, const Person&)>;

private:
    // Internal node for singly linked list
    struct Node {
        std::shared_ptr<Person> person;
        Node* next;
        Node(const std::shared_ptr<Person>& p, Node* n = nullptr) : person(p), next(n) {}
    };

    Node* head;
    Comparator comp;

public:
    // The "using" command below has the same meaning as "typedef"
    

    // @comp = a function to compare people to one another. 
    // should return "true" if second person > first person.
    PList();
	PList(Comparator comp);
    ~PList();

    // Should insert to the HEAD of the list.
    void insert(const std::shared_ptr<Person>& person);
    void print() const;

    // Transforms all people in the list using "func" input parameter.
    void transform(TransformFunc func);

    class iterator {
    public:
        iterator(Node* start = nullptr);
        explicit iterator(void* nodePtr);
        iterator& operator++();
        bool operator!=(const iterator& other) const;
        std::shared_ptr<Person>& operator*();
    private:
        void* m_node;
        friend class PList;
    };

    iterator begin();
    iterator end();


};
#endif // QUESTION_H
