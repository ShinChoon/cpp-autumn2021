
#ifndef TRIPLE_H
#define TRIPLE_H 
/* Add include guards here */
#include <typeinfo>
template <typename T1, typename T2, typename T3>
class Triple{
    public:
        Triple(const T1& one, const T2& two, const T3& three):one_(one), two_(two), three_(three){
        }
        Triple(const Triple<T1, T2, T3>& TR){
            one_ = TR.First();
            two_ = TR.Second();
            three_ = TR.Third();
        }

        Triple(){}

        const T1& First()const{
            return one_;
        }
        const T2 &Second()const
        {
            return two_;
        }

        const T3 &Third()const
        {
            return three_;
        }

       Triple<T1, T2, T3> &operator=(const Triple<T1, T2, T3> &TR2)
        {
            one_ = TR2.First();
            two_ = TR2.Second();
            three_ = TR2.Third();
            return *this;
        }

    private:
        T1 one_;
        T2 two_;
        T3 three_;
};

template <typename T1, typename T2, typename T3>
bool IsHomogenous(const Triple <T1, T2, T3> &TR)
{
    bool flag1 = typeid(TR.First()).name()==typeid(TR.Second()).name();
    bool flag2 = typeid(TR.Second()).name()== typeid(TR.Third()).name();
    return flag1&&flag2;
}

template <typename T1, typename T2, typename T3>
bool operator==(const Triple<T1, T2, T3> &TR1, const Triple<T1, T2, T3> &TR2)
{
    bool flag = true;
    if ((TR1.First() != TR2.First()) || (TR1.Second() != TR2.Second()) || (TR1.Third() != TR2.Third()))
        flag = false;
    return flag;
}
template <typename T1, typename T2, typename T3>
bool operator!=(const Triple<T1, T2, T3> &TR1, const Triple<T1, T2, T3> &TR2)
{
    bool flag = false;
    if ((TR1.First() != TR2.First()) || (TR1.Second() != TR2.Second()) || (TR1.Third() != TR2.Third()))
        flag = true;
    return flag;
}
template <typename T1, typename T2, typename T3>
std::ostream &operator<<(std::ostream &os, const Triple<T1, T2, T3>& TR)
{
    os << "[" << TR.First() << ", " << TR.Second() << ", " << TR.Third() << "]";
    return os;
}
    /* Class: Triple
     * -------------
     * The template class Triple is a container class, which holds three values.
     * All of the values can be of different type. All of the values should be
     * private.
     *
     * The constructor of the class takes three const references to values as a
     * parameter. The parameters are in order, in other words, after construction
     * the first parameter should be accessible through the public member function
     * First, the second parameter through the public member function Second, and
     * the third through the public member function Third.
     *
     * The default empty constructor should also work.
     *
     * The Triple class should also support the copy constructor, and assignment
     * operations.
     */

    /* Public member functions:
     * ------------------------
     * The Triple class has three public member functions, which are used to
     * access the stored elements. All three should work with const instances
     * of Triple.
     *
     * Function: First
     * The function takes no parameters.
     * The function returns a const reference to the first value of the triple.
     *
     * Function: Second
     * The function takes no parameters.
     * The function returns a const reference to the second value of the triple.
     *
     * Function: Third
     * The function takes no parameters.
     * The function returns a const reference to the third value of the triple.
     */

    /* Non-member functions:
     * ---------------------
     * Function: IsHomogenous
     * The function is a non-member function that takes a Triple as a parameter.
     * The function returns a boolean value indicating whether the triple is
     * homogenous or not. A triple is homogenous if all of its three values are of
     * the same type.
     * Hint: specialisation can help you here.
     */

    /* Operator overloads:
     * -------------------
     * The triple class should support the following operators:
     *
     * Assignment operator, =
     * The default functionality should do here.
     *
     * Equality operator, ==
     * You can assume that all the values in the triple can be compared by the
     * == -operator. Two triples are equal if the corresponding values in both
     * of the triples are equal.
     *
     * Inequality operator, !=
     * You can assume that all the values in the triple can be compared by the
     * != -operator. Two triples are inequal if even one corresponding value in
     * the triples is different.
     *
     * The output stream operator, <<
     * You can assume that all the values in the triple support the << -operator.
     * The triple should be printed to the output stream in the following format:
    [<first value>, <second value>, <third value>]
     * Note that there is NO new line at the end of the output.
     */

    /* Remember the endif here to close the header guards */
#endif