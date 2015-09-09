#ifndef MEDIT_MEDITBASE_INTERFACE_ICLONABLE_HPP
#define MEDIT_MEDITBASE_INTERFACE_ICLONABLE_HPP

#include <memory>

using namespace std;


namespace Medit
{
namespace MeditBase
{
namespace Interface
{


template<class BASE_CLASS>
class IClonable
{

protected:

    /**
     * clone given item as type
     * @iparam CURR_CLASS current class type
     * @param context context used as original
     * @return cloned context
     */
    template<class CURR_CLASS>
    BASE_CLASS *cloneItem()
    {
        allocator<CURR_CLASS> alloc;
        CURR_CLASS *retVal = alloc.allocate(1);

        alloc.construct(retVal, *context);

        return retVal;
    }

public:

    /**
     * @brief basic allocator
     */
    typedef allocator<BASE_CLASS> Allocator;

    /**
     * @brief create copy of current instance
     * @return cloned instance
     */
    virtual BASE_CLASS *clone() const = 0;

};

}
}
}


#endif // MEDIT_MEDITBASE_INTERFACE_ICLONABLE_HPP
