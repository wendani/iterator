#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <map>

int main(int argc, char *argv[])
{
    {
        std::string s = "012345678";
        std::cout << s << std::endl;

        auto it = s.begin() + 4;
        auto rit = make_reverse_iterator(it);
        std::cout << *rit << std::endl; // 3
        std::cout << *it << std::endl;  // 4
        s.erase(next(rit).base());
        std::cout << *rit << std::endl; // 4
        std::cout << *it << std::endl;  // 5
        std::cout << s << std::endl;    // 01245678
    }

    {
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

        it = m_toSync.find('d');
        auto rit = make_reverse_iterator(it);
        std::cout << rit->first << " => " << rit->second << std::endl;  // c => 30
        std::cout << it->first << " => " << it->second << std::endl;    // d => 40
        std::cout << std::endl;

        m_toSync.erase(next(rit).base());
        std::cout << rit->first << " => " << rit->second << std::endl;  // b => 20
        std::cout << it->first << " => " << it->second << std::endl;    // d => 40
        std::cout << std::endl;

        m_toSync.erase(next(rit).base());
        std::cout << rit->first << " => " << rit->second << std::endl;  // a => 10
        std::cout << it->first << " => " << it->second << std::endl;    // d => 40
    }

    {
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

        it = m_toSync.find('d');
        // erase by iterator
        m_toSync.erase(it++);
        std::cout << it->first << " => " << it->second << std::endl;    // e => 50
        std::cout << std::endl;

        it = m_toSync.erase(it);
        std::cout << it->first << " => " << it->second << std::endl;    // f => 60
        std::cout << std::endl;

        it++;
        std::cout << it->first << " => " << it->second << std::endl;
        std::cout << std::endl;

        for (it = m_toSync.begin(); it != m_toSync.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
