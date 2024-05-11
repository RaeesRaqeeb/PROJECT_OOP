#pragma once

//THis is baase class from which functions are overrided 
class Base_class
{
public:
    virtual ~Base_class();
    virtual void Draw()=0;
    virtual void Update()=0;
    virtual void MoveMents()=0;
    virtual void Reset()=0;
    
};