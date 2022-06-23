#pragma once              //Заголовочный файл Hash_ Twin_Chain.h
#include "Lists.h"
namespace hashTC
{
    struct Object
    {
        int size;
        int(*FunKey)(void*);
        listx::Object* Hash;
        Object(int s, int(*f)(void*))
        {
            size = s;
            FunKey = f;
            Hash = new listx::Object[size];
            for (int i = 0; i < size; i++) {
                Hash[i] = listx::create();
            }
        };
        int hashFunction(void* data);
        bool insert(void* data);
        listx::Element* search(void* data);
        bool deleteByData(void* data);
        void Scan();
    };
    Object create(int size, int(*f)(void*));
}
