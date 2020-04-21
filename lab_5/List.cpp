#include "List.h"

namespace buyer
{
void List::add(const Data &data)
{
    if (size() == 0) {
        push_back(data);
    } else if (end()->getSurname() < data.getSurname()) {
        push_front(data);
    } else {
        for (auto iter = begin(); iter != end(); ++iter) {
            if (iter->getSurname() > data.getSurname()) {
                emplace(--iter, data);
                break;
            }
        }
    }
}

void List::remove(const std::string key) {
    bool flag = false;

    for (auto iter = begin(); iter != end(); ++iter) {
        if (iter->getSurname() == key) {
            erase(iter);
            flag = true;
            break;
        }
    }
    if (flag) {
        std::cout << "Bad key!" << std::endl;
    }
}
void List::update(int pos, Data record)
{
    int id = 0;
    for (auto iter = begin(); iter != end(); ++iter)
    {
        if (id == pos)
        {
            erase(iter);
            add(record);
            return;
        }
        ++id;
    }
}
void List::print()
{
    copy(begin(), end(), std::ostream_iterator<Data>(std::cout));
}
void List::printReversed()
{
    copy(rbegin(), rend(), std::ostream_iterator<Data>(std::cout));
}

Data List::search(Data record, bool (*compareFunction)(Data, Data))
{
    for (auto iter = begin(); iter != end(); ++iter) {
        if (compareFunction(record, *iter)) {
            std::cout << "Element: " << *iter 
                    << ' ' << "is founded.";
            return *iter;
        }
    }
    return *(new Data);
}
List List::filter(Data record, bool (*compareFunction)(Data, Data))
{
    List list;
    for (auto iter = begin(); iter != end(); ++iter) {
        if (compareFunction(record, *iter)) {
            list.add(*iter);
        }
    }
    return list;
}

void List::load(const char *filename)
{
    std::ifstream file(filename);
    Data data;

    while (file.good()) {
        file >> data;
        add(data);
    }
    file.close();
}
void List::save(const char *filename)
{
    std::ofstream file(filename);

    for (auto iter = begin(); iter != end(); ++iter) {
        file << *iter;
    }
    file.close();
}
} 