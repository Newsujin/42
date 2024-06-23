#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN {
    private:
        int result;
        std::stack<int> stack;

        bool isOperator(char token) const;
        int performOperator(char op, int n1, int n2) const;

    public:
        RPN();
        RPN(const RPN& rhs);
        RPN& operator=(const RPN& rhs);
        ~RPN();

        void execute(std::string& str);
        int getResult() const;
};

#endif