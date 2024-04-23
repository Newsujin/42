#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "argc error" << std::endl, 1);

    if (!av[1][0] || !av[2][0])
        return (std::cout << "argv length error" << std::endl, 1);

    std::string infile = av[1];
    std::ifstream ifs(infile.c_str());
    if (ifs.fail())
        return (std::cout << infile << " open error" << std::endl, 1);

    std::string outfile = infile + ".replace";
    std::ofstream ofs(outfile.c_str());
    if (ofs.fail())
        return (std::cout << outfile << " open error" << std::endl, 1);
   
    std::string s1 = av[2];
    std::string s2 = av[3];
    int len1 = s1.length();
    int len2 = s2.length();
    std::string line;
    while (1)
    {
        std::getline(ifs, line);
        size_t pos = 0;
        while (1)
        {
            pos = line.find(s1, pos);
            if (pos == std::string::npos)
                break;
            line.erase(pos, len1);
            line.insert(pos, s2);
            pos += len2;
        }
        ofs << line;
        if (ifs.eof())
            break;
        ofs << std::endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}