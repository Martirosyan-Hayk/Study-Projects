#include <iostream>
#include <string>
#include <vector>
#include <sstream>

struct Item
{

    Item() 
    { }
    Item(std::string name, std::string type) : m_item_name{ name }, m_item_type{ set_item_type(type) }
    { }
   
    std::string get_item_name_fld(std::string& item_name) const
    {
        for (int i = 0; i < m_items.size(); ++i)
        {
            if (item_name == m_items[i]->m_item_name)
            {
                if (m_items[i]->m_item_type == true)
                {
                    return m_items[i]->m_item_name;
                }
                else
                {
                    return " ";
                }
            }
            else
            {
                return " ";
            }
        }
    }
    std::string get_item_name(std::string& item_name) const
    {
        for (int i = 0; i < m_items.size(); ++i)
        {
            if (item_name == m_items[i]->m_item_name)
            {
                return m_items[i]->m_item_name;
               
            }
            else
            {
                return " ";
            }
        }
    }
    Item* get_item(std::string& item_name) 
    {
        for (int i = 0; i < m_items.size(); ++i)
        {
            if (item_name == m_items[i]->m_item_name)
            {           
                return m_items[i];
            }
            else
            {
                return nullptr;
            }
        }
    }
    std::vector<Item*>& delete_item_index(std::vector<Item*>& items,std::string& item_name)
    {
        for (int i = 0; i < items.size(); ++i)
        {
            if (item_name == items[i]->m_item_name)
            {
                std::vector<Item*> newitem;
                int j = 0;
                for (; items[j]->m_item_name != item_name; ++j)
                {
                    newitem.push_back(items[j]);
                }
                ++j;
                for (; j < items.size(); ++j)
                {
                    newitem.push_back(items[j]);
                }
                items = newitem;
                return items;
            }

        }
        std::cout << "No folder or file with that name was found" << std::endl;
        return items;
    }
    bool set_item_type(std::string& com_name)
    {
        if (com_name == "mkdir")
        {
            m_item_type = true;
        }
        else
        {
            m_item_type = false;
        }
        return m_item_type;
    }


    std::vector<Item*> m_items;
    std::string m_item_name;
    bool m_item_type = true;
};

Item* in_now_fld;
Item* in_previous_fld;

int main()
{
    std::string word_comm, word_name;
    Item root;
    root.m_item_name = "root";
    in_now_fld = &root;
    in_previous_fld = &root;
    std::string command;
    std::cout << "Enter a command: "; 
    std::getline(std::cin, command);
    

     while (command != "exit")
     {
         std::stringstream check1(command);
         std::getline(check1, word_comm, ' ');
         std::getline(check1, word_name, ' ');

        if (word_comm == "ls")
        {
            
            if (root.m_items.size() == 0)
            {
                std::cout << "Empty" << std::endl;
            }
            else
            {
                for (int i = 0; i < in_now_fld->m_items.size(); ++i)
                {
                    std::cout << in_now_fld->m_items[i]->m_item_name << "; ";
                }
                std::cout << std::endl;
            }
        }
        else if (word_comm == "mkdir")
        {

            in_now_fld->m_items.push_back(new Item(word_name, word_comm));
            
        }
        else if (word_comm == "touch")
        {
            in_now_fld->m_items.push_back(new Item(word_name, word_comm));
        }
        else if (word_comm == "cd")
        {
            if (word_name == "..")
            {
                in_now_fld = in_previous_fld;
                --in_previous_fld;
            }

            if ( word_name == in_now_fld->get_item_name_fld(word_name))
            {
                in_previous_fld = in_now_fld;
                in_now_fld = in_previous_fld->m_items[0];
            }
            else
            {
                std::cout << "not variable fil or folder" << std::endl;
            }
        }
        else if (word_comm == "rmdir")
        {
            if (word_name == in_now_fld->get_item_name(word_name))
            {
                in_now_fld->delete_item_index(in_now_fld->m_items, word_name);
            }
            else
            {
                std::cout << "the folder is nor charvel" << std::endl;     
            }
        }
        else if (word_comm == "pwd") 
        {
            std::cout << "(" << in_now_fld->m_item_name << ")" << std::endl;
        }

        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
     }


    return 0;
}


