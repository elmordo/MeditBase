#ifndef MEDIT_MEDITBASE_ALLOCATOR_HPP
#define MEDIT_MEDITBASE_ALLOCATOR_HPP

#include <memory>

using namespace std;


namespace Medit
{
namespace MeditBase
{

template<typename T>
class Allocator : public allocator<T>
{
public:

    typedef allocator<T> AllocatorBase;

    /**
     * @brief T template argument alias
     */
    typedef T TypeName;

    /**
     * @brief pointer to allocated type
     */
    typedef T* TypePtr;

    /**
     * @brief allocator type
     */
    typedef Allocator<T> AllocatorType;

    /**
     * @brief reference to allocator
     */
    typedef Allocator<T>& AllocatorRef;

    /**
     * @brief empty constructor
     */
    Allocator() throw();

    /**
     * @brief copytor
     * @param original instance with original data
     */
    Allocator(const AllocatorRef original) throw();

    /**
     * @brief destructor
     */
    virtual ~Allocator() throw();

    /**
     * @brief allocate data abd construct instances
     * @param n number of instances
     * @param args set of arguments for constructor
     * @tparam Args set of arguments
     */
    template<typename... Args>
    TypePtr allocateAndConstruct(size_t n, Args... args);

    /**
     * @brief destroy allocated instances
     * @param pointer pointer to the first instance
     * @param n number of instances
     */
    void destroyAndDeallocate(TypePtr pointer, size_t n=1);

};

template<typename T>
Allocator<T>::Allocator() throw()
{
}

template<typename T>
Allocator<T>::Allocator(AllocatorRef original) throw() : AllocatorBase(original)
{
}

template<typename T>
Allocator<T>::~Allocator() throw()
{
}

template<typename T>
template<typename... Args>
T *Allocator<T>::allocateAndConstruct(size_t n, Args... args)
{
    TypePtr instance = allocator<T>::allocate(n);
    construct(instance, forward<Args>(args)...);

    return instance;
}

template<typename T>
void Allocator<T>::destroyAndDeallocate(TypePtr pointer, size_t n)
{
    allocator<T> alloc;

    for (size_t i = 0; i < n; ++i)
    {
        alloc.destroy(pointer + i);
    }

    alloc.deallocate(pointer, n);
}


}
}


#endif // MEDIT_MEDITBASE_ALLOCATOR_HPP
