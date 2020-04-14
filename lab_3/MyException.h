#include <string>

namespace buyer
{
    class MyException : public std::exception
    {
    private:
        std::string m_error;
    
    public:
        MyException(std::string error = "default") : m_error("My exception: " + error) {}
    
        const char *what() const noexcept { return m_error.c_str(); }
    };
    
    class ListException : public MyException
    {
    public:
        ListException(std::string error = "default") : MyException("List exception: " + error) {}
    };
    
    class ListWrongIndexException : public ListException
    {
    public:
        ListWrongIndexException(int err_ind) : ListException("Wrong index - [" + std::to_string(err_ind) + "]") {}
    };
    
    class ListEmptyException : public ListException
    {
    public:
        ListEmptyException() : ListException("Empty list") {}
    };
    
    class ListFileReadException : public ListException
    {
    public:
        ListFileReadException() : ListException("File reading error") {}
    };
    
    class ListFileWriteException : public ListException
    {
    public:
        ListFileWriteException() : ListException("File writing error") {}
    };
}