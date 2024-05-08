#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain &rhs);
        Brain& operator=(const Brain &rhs);
        ~Brain();

        std::string *getIdeas();
        void setIdea(int idx, std::string idea);
};

#endif