
#include "DefaultTemplateGemSystemComponent.h"

#include <DefaultTemplateGem/DefaultTemplateGemTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace DefaultTemplateGem
{
    AZ_COMPONENT_IMPL(DefaultTemplateGemSystemComponent, "DefaultTemplateGemSystemComponent",
        DefaultTemplateGemSystemComponentTypeId);

    void DefaultTemplateGemSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<DefaultTemplateGemSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void DefaultTemplateGemSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("DefaultTemplateGemService"));
    }

    void DefaultTemplateGemSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("DefaultTemplateGemService"));
    }

    void DefaultTemplateGemSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void DefaultTemplateGemSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    DefaultTemplateGemSystemComponent::DefaultTemplateGemSystemComponent()
    {
        if (DefaultTemplateGemInterface::Get() == nullptr)
        {
            DefaultTemplateGemInterface::Register(this);
        }
    }

    DefaultTemplateGemSystemComponent::~DefaultTemplateGemSystemComponent()
    {
        if (DefaultTemplateGemInterface::Get() == this)
        {
            DefaultTemplateGemInterface::Unregister(this);
        }
    }

    void DefaultTemplateGemSystemComponent::Init()
    {
    }

    void DefaultTemplateGemSystemComponent::Activate()
    {
        DefaultTemplateGemRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void DefaultTemplateGemSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        DefaultTemplateGemRequestBus::Handler::BusDisconnect();
    }

    void DefaultTemplateGemSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace DefaultTemplateGem
