#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include <memory>
#include <iostream>

int refCounter::shallowcount = 1;//initialized. shallowcount will always increase
template <typename T>
class RestrictedPtr{
    public:
        RestrictedPtr():tr(nullptr){
            // referenceCounter->increment();
            count = referenceCounter->shallowcount;
            }
        RestrictedPtr(T* raw):tr(raw){
            // referenceCounter->increment();
            count = referenceCounter->shallowcount;
        }
        RestrictedPtr(RestrictedPtr& Rp){
            if (referenceCounter->shallowcount < 3)
            {
                tr = Rp.GetPointer();
                referenceCounter->increment();
                count = referenceCounter->shallowcount;
            }
            else
            {
                count = 1;
                referenceCounter->increment();//?
                tr = nullptr;
            }
        }

        ~RestrictedPtr()
        {
            if (referenceCounter->shallowcount == 0)
            {
                delete tr;
                tr = nullptr;
            }
            else
                referenceCounter->Deference();

        }

        RestrictedPtr& operator=(RestrictedPtr &lhs)
        {
            // assignments.. modify the use referenceCounter->shallowcount
            if (referenceCounter->shallowcount < 3)
            {
                tr = lhs.GetPointer();
                referenceCounter->increment();
                count = referenceCounter->shallowcount;
            }
            else
            {
                count = 1;
                referenceCounter->shallowcount++;
                tr = nullptr;
            }
            return *this;
        }
        // other overloads of operator=

        T& GetData(){
            return *tr;
        }

        T* GetPointer()
        {
            return tr;

        }

        int GetRefCount()
        {
            return count;
        }

    private:
        refCounter* referenceCounter;
        T* tr;
        int count=0; //lcoal count  could be assigned to 1 when the shallow account >=3
};

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference referenceCounter->shallowcount
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference referenceCounter->shallowcount drops to 0, the referenced
    pointer's memory should be released. If the reference referenceCounter->shallowcount is already 3 when copying,
    the copier should set it's pointer to nullptr and reference referenceCounter->shallowcount to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/

#endif