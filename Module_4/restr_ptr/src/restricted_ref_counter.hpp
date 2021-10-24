#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to
class refCounter{
    public:
        static int shallowcount;
        refCounter(){}
        ~refCounter(){}
        int GetCount(){return shallowcount;};
        void Deference(){shallowcount--;}
        void increment(){shallowcount++;}


};
#endif