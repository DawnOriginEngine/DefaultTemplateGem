
#include <DefaultTemplateGem/DefaultTemplateGemTypeIds.h>
#include <DefaultTemplateGemModuleInterface.h>
#include "DefaultTemplateGemSystemComponent.h"

namespace DefaultTemplateGem
{
    class DefaultTemplateGemModule
        : public DefaultTemplateGemModuleInterface
    {
    public:
        AZ_RTTI(DefaultTemplateGemModule, DefaultTemplateGemModuleTypeId, DefaultTemplateGemModuleInterface);
        AZ_CLASS_ALLOCATOR(DefaultTemplateGemModule, AZ::SystemAllocator);
    };
}// namespace DefaultTemplateGem

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), DefaultTemplateGem::DefaultTemplateGemModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_DefaultTemplateGem, DefaultTemplateGem::DefaultTemplateGemModule)
#endif
