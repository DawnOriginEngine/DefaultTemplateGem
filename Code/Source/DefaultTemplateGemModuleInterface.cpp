
#include "DefaultTemplateGemModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <DefaultTemplateGem/DefaultTemplateGemTypeIds.h>

#include <Clients/DefaultTemplateGemSystemComponent.h>

namespace DefaultTemplateGem
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(DefaultTemplateGemModuleInterface,
        "DefaultTemplateGemModuleInterface", DefaultTemplateGemModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(DefaultTemplateGemModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(DefaultTemplateGemModuleInterface, AZ::SystemAllocator);

    DefaultTemplateGemModuleInterface::DefaultTemplateGemModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            DefaultTemplateGemSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList DefaultTemplateGemModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<DefaultTemplateGemSystemComponent>(),
        };
    }
} // namespace DefaultTemplateGem
