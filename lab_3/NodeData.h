#pragma once

#include "Node.h"
#include "Data.h"
#include "exception"

namespace buyer
{
    class NodeData : public Node, public Data
    {
    public:
        NodeData() : Node(), Data() {}
        NodeData(const Data &data) : Node(), Data(data) {}
        NodeData(const NodeData &element) : Node(element), Data(element) {}

        Data getData() const;

        virtual NodeData *copyNode() override;
        virtual NodeData *readData(std::istream &) override;
        virtual void showData(std::ostream &) const override;
        virtual bool compareSurname(const char*, const char) const override;
        virtual bool compareAccountNumber(const int, const char) const override;
        virtual bool compareTown(const char*, const char) const override;
    };
}