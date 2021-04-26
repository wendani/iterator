#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>

int main(int argc, char *argv[])
{
#if 0
    std::string s = "012345678";
    std::cout << s << std::endl;

    auto it = s.begin() + 4;
    auto rit = make_reverse_iterator(it);
    std::cout << *rit << std::endl;
    std::cout << *it << std::endl;
    s.erase(next(rit).base());
    std::cout << *rit << std::endl;
    std::cout << *it << std::endl;
    std::cout << s << std::endl;
#endif

    std::map<char, int> m_toSync;
    std::map<char, int>::iterator it;

    // insert some values:
    m_toSync['a'] = 10;
    m_toSync['b'] = 20;
    m_toSync['c'] = 30;
    m_toSync['d'] = 40;
    m_toSync['e'] = 50;
    m_toSync['f'] = 60;

    for (it = m_toSync.begin(); it != m_toSync.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    std::cout << std::endl;

#if 0
    it = m_toSync.find('b');
    // erasing by iterator
    //m_toSync.erase(it);
    m_toSync.erase(it++);
    std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    it++;
    std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
#endif

    it = m_toSync.find('d');
    auto rit = make_reverse_iterator(it);
    std::cout << rit->first << " => " << rit->second << std::endl;
    std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    m_toSync.erase(next(rit).base());
    std::cout << rit->first << " => " << rit->second << std::endl;
    std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;

    m_toSync.erase(next(rit).base());
    std::cout << rit->first << " => " << rit->second << std::endl;
    std::cout << it->first << " => " << it->second << std::endl;

    return 0;
}
