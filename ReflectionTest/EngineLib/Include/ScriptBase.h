#pragma once

#include <iostream>
#include <rttr/registration>

using namespace rttr;

#define SETUP_SCRIPT(...) RTTR_ENABLE(__VA_ARGS__)

#define IMPLEMENT_CONSTRUCTOR .constructor<>()
#define IMPLEMENT_FUNCTION(name, func) .method(name, func)
#define IMPLEMENT_SCRIPT(name, type, ...) RTTR_PLUGIN_REGISTRATION { registration::class_<type>(name) __VA_ARGS__ }

#define EDITOR_PROPERTY(name, prop) .property(name, prop)

class Component
{
SETUP_SCRIPT()

public:
	virtual ~Component() {}

protected:
	void GetOwner()
	{
		std::cout << "GetOwner called" << std::endl;
	}
};

class ScriptBase : public Component
{
SETUP_SCRIPT(Component)

public:
	virtual void OnStart() {}
	virtual void OnUpdate() {}

};

