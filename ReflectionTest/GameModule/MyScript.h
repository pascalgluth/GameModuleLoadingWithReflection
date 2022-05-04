#pragma once

#include <iostream>

#include "ScriptBase.h"

class MyScript : public ScriptBase
{
SETUP_SCRIPT(ScriptBase)

public:
    MyScript() {}

    ~MyScript()
    {
        std::cout << "Destructor called" << std::endl;
    }
    
    void OnStart() override
    {
        std::cout << "Script started adfdafad" << std::endl;

        GetOwner();
    }

    int data = 5;
};

IMPLEMENT_SCRIPT
(
    "MyScript", MyScript,
    IMPLEMENT_CONSTRUCTOR
    EDITOR_PROPERTY("data", &MyScript::data);
)



/*RTTR_PLUGIN_REGISTRATION
{
   rttr::registration::class_<MyScript>("MyScript") // <- Name
        .constructor<>()
        .method("OnStart", &MyScript::OnStart); // <- methode zum exportieren
}*/
