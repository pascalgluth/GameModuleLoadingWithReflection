#include <iostream>
#include <rttr/type>

#include "ScriptBase.h"

#pragma comment(lib, "rttr_core_d.lib")

int main()
{
    using namespace rttr;

    library lib("GameModule");

    if (!lib.load())
    {
        std::cerr << lib.get_error_string() << std::endl;
        return -1;
    }

    std::cout << "Library loaded" << std::endl;
    std::cout << std::endl;

    {
        for (auto t : lib.get_types())
        {
            if (t.is_class() && !t.is_wrapper())
            {
                std::cout << t.get_name() << std::endl;
            }
        }
    }

    type t = type::get_by_name("MyScript");

    try
    {
        variant instance = t.create();

        ScriptBase* scriptPtr = instance.get_value<ScriptBase*>();
        if (!scriptPtr)
        {
            std::cerr << "Failed to cast to script pointer" << std::endl;
        }

        scriptPtr->OnStart();
        
        //t.invoke("OnStart", instance, {});

        for(auto p : t.get_properties())
        {
            std::cout << "Prop: " << p.get_value(instance).to_int32() << std::endl;
        }

        /*bool run = true;
        while (run)
        {
            std::string val;
            std::cin >> val;

            if (val == "reload")
            {
                t.get_destructor().invoke(instance);

                if (!lib.unload())
                {
                    std::cerr << lib.get_error_string() << std::endl;
                    return -1;
                }
                std::cout << "Library unloaded" << std::endl;

                int val2;
                std::cin >> val2;

                if (!lib.load())
                {
                    std::cerr << lib.get_error_string() << std::endl;
                    return -1;
                }

                std::cout << "Library loaded" << std::endl;
                std::cout << std::endl;

                t = type::get_by_name("MyScript");
                instance = t.create();
                t.invoke("Start", instance, {});
            }

        }*/

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    
    //variant instance = t.create();

    //t.invoke("Test", instance, {});

    std::cout << std::endl;

    if (!lib.unload())
    {
        std::cerr << lib.get_error_string() << std::endl;
        return -1;
    }

    std::cout << "Library unloaded" << std::endl;

    return 0;
}
