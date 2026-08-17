/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:31:46 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/15 16:01:50 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <list>

int main()
{
    std::cout << "--- 1. STANDARD SUBJECT TEST ---" << std::endl;
    {
        MutantStack<int> mstack;
        
        mstack.push(5);
        mstack.push(17);
        
        std::cout << "Top element: " << mstack.top() << std::endl;
        
        mstack.pop();
        
        std::cout << "Size after pop: " << mstack.size() << std::endl;
        
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        std::cout << "Iterating through MutantStack:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        
        std::stack<int> s(mstack); 
    }

    std::cout << "\n--- 2. COMPARISON WITH STD::LIST ---" << std::endl;
    {
        std::list<int> list;
        
        list.push_back(5);
        list.push_back(17);
        
        std::cout << "Top element: " << list.back() << std::endl;
        
        list.pop_back();
        
        std::cout << "Size after pop: " << list.size() << std::endl;
        
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        
        ++it;
        --it;
        
        std::cout << "Iterating through std::list:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "\n--- 3. REVERSE ITERATOR TEST ---" << std::endl;
    {
        MutantStack<int> mstack;
        for (int i = 1; i <= 5; ++i)
            mstack.push(i);
        
        std::cout << "Reverse iteration (expected 5 4 3 2 1):" << std::endl;
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        
        while (rit != rite)
        {
            std::cout << *rit << " ";
            ++rit;
        }
        std::cout << std::endl;
    }

    std::cout << "\n--- 4. ORTHODOX CANONICAL FORM TEST ---" << std::endl;
    {
        MutantStack<int> mstack1;
        mstack1.push(42);
        mstack1.push(21);
        
        MutantStack<int> mstack2(mstack1);
        std::cout << "Copied stack top (expected 21): " << mstack2.top() << std::endl;
        
        MutantStack<int> mstack3;
        mstack3 = mstack1;
        std::cout << "Assigned stack top (expected 21): " << mstack3.top() << std::endl;
        
        mstack1.pop();
        std::cout << "Original stack after pop (expected 42): " << mstack1.top() << std::endl;
        std::cout << "Copied stack top remains (expected 21): " << mstack2.top() << std::endl;
    }
    
    std::cout << "\n--- 5. ALTERNATIVE CONTAINER TEST (std::vector) ---" << std::endl;
    {
        MutantStack<int, std::vector<int> > vstack;
        vstack.push(100);
        vstack.push(200);
        
        std::cout << "Vector-powered stack top (expected 200): " << vstack.top() << std::endl;
        
        MutantStack<int, std::vector<int> >::iterator it = vstack.begin();
        std::cout << "Vector-powered stack begin (expected 100): " << *it << std::endl;
    }

    return 0;
}
