#include "Question.h"

Person::Person(const std::string& name, int age, const std::string& address) : name(name), age(age), address(address)
{
}

void Person::print() const {
    std::cout << "Name: " << name << ", Age: " << age << ", Address: " << address;
}

bool Person::operator==(const Person& other) const {
    if (name == other.name && age == other.age && address == other.address) {
        return true;
    }
    return false;
}

PList::PList()
    : head(nullptr),
    comp([](const Person&, const Person&) { return false; })
{
}

PList::PList(Comparator comp)
    : head(nullptr),
    comp(std::move(comp))
{
}

PList::~PList() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}

void PList::insert(const std::shared_ptr<Person>& person) {
    for (Node* n = head; n != nullptr; n = n->next) {
        if (n->person == person)
            return;
        if (*(n->person) == *person)
            return;
    }
    head = new Node(person, head);
}

void PList::print() const {
    for (Node* n = head; n != nullptr; n = n->next) {
        if (n->person)
            n->person->print();
    }
}

void PList::transform(TransformFunc func) {
    for (Node* n = head; n != nullptr; n = n->next) {
        if (n->person) {
            Person transformed = func(*(n->person));
            n->person = std::make_shared<Person>(transformed);
        }
    }
}

PList::iterator::iterator(PList::Node* start) : m_node(static_cast<void*>(start)) {
}

PList::iterator::iterator(void* nodePtr) : m_node(nodePtr) {
}

PList::iterator& PList::iterator::operator++() {
    if (!m_node) return *this;
    PList::Node* n = static_cast<PList::Node*>(m_node);
    n = n->next;
    m_node = static_cast<void*>(n);
    return *this;
}

bool PList::iterator::operator!=(const iterator& other) const {
    return m_node != other.m_node;
}

std::shared_ptr<Person>& PList::iterator::operator*() {
    PList::Node* n = static_cast<PList::Node*>(m_node);
    return n->person;
}

PList::iterator PList::begin() {
    return iterator(head);
}

PList::iterator PList::end() {
    return iterator(static_cast<PList::Node*>(nullptr));
}