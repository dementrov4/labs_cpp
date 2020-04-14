#include "NodeData.h"

namespace buyer
{
    Data NodeData::getData() const
    {
        return *this;
    }

    NodeData *NodeData::copyNode()
    {
        return new NodeData(*this);
    }

    NodeData *NodeData::readData(std::istream &in)
    {
        in >> *this;
        return this;
    }

    void NodeData::showData(std::ostream &out) const
    {
        out << *this;
    }

    bool NodeData::compareSurname(const char* condition, const char sign) const 
    {
        try {
            switch (sign)
            {
            case '>':
                return strcmp(getData().getSurname(), condition) > 0; 
                break;
            case '<':
                return strcmp(getData().getSurname(), condition) < 0;
                break;
            case '=':
                return strcmp(getData().getSurname(), condition) == 0;
                break;
            default:
                throw std::invalid_argument("bad sign");
                break;
            }
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        return false;
    }

    bool NodeData::compareAccountNumber(const int condition, const char sign) const
    {
        try
        {
            switch (sign)
            {
            case '>':
                return getData().getAccountNumber() > condition;
                break;
            case '<':
                return getData().getAccountNumber() < condition;
                break;
            case '=':
                return getData().getAccountNumber() == condition;
                break;
            default:
                throw std::invalid_argument("bad sign");
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return false;
    }

    bool NodeData::compareTown(const char *condition, const char sign) const
    {
        try
        {
            switch (sign)
            {
            case '>':
                return strcmp(getData().getTown(), condition) > 0;
                break;
            case '<':
                return strcmp(getData().getTown(), condition) < 0;
                break;
            case '=':
                return strcmp(getData().getTown(), condition) == 0;
                break;
            default:
                throw std::invalid_argument("bad sign");
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return false;
    }
} 